/*
字典 strList 中从字符串 beginStr 和 endStr
的转换序列是一个按下述规格形成的序列： 序列中第一个字符串是 beginStr。
序列中最后一个字符串是 endStr。
每次转换只能改变一个位置的字符（例如 ftr 可以转化 fty ，但 ftr 不能转化 frx）。
转换过程中的中间字符串必须是字典 strList 中的字符串。
beginStr 和 endStr 不在 字典 strList 中
字符串中只有小写的26个字母
给你两个字符串 beginStr 和 endStr 和一个字典 strList，找到从 beginStr 到 endStr
的最短转换序列中的字符串数目。 如果不存在这样的转换序列，返回 0。
第一行包含一个整数 N，表示字典 strList 中的字符串数量。
第二行包含两个字符串，用空格隔开，分别代表 beginStr 和 endStr。 后续 N
行，每行一个字符串，代表 strList 中的字符串。 输出描述 输出一个整数，代表从
beginStr 转换到 endStr
需要的最短转换序列中的字符串数量。如果不存在这样的转换序列，则输出 0。
*/
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  string beginStr, endStr;
  unordered_set<string> strSet;
  int N;
  cin >> N;
  cin >> beginStr >> endStr;
  for (int i = 0; i < N; i++) {
    string element;
    cin >> element;
    strSet.insert(element);
  }
  //   记录strSet里的字符串是否被访问过，同时记录路径长度
  unordered_map<string, int> visitMap;  // <记录的字符串，路径长度>

  //   初始化队列
  queue<string> que;
  que.push(beginStr);
  visitMap.insert(pair<string, int>(beginStr, 1));
  while (!que.empty()) {
    string word = que.front();
    que.pop();
    int path = visitMap[word];
    // 开始在这个str中 挨个字符去替换
    for (int i = 0; i < word.size(); i++) {
      // 内层for循环结束后 复原newWord，对newWord的下一位置的字符进行变换
      string newWord = word;
      for (int j = 0; j < 26; j++) {
        newWord[i] = j + 'a';
        if (newWord == endStr) {
          cout << path + 1;
          return 0;
        }

        if (strSet.find(newWord) != strSet.end() &&
            visitMap.find(newWord) == visitMap.end()) {
          visitMap.insert({newWord, path + 1});
          que.push(newWord);
        }
      }
    }
  }
  cout << 0;
  return 0;
}