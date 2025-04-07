#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

// 定义一个结构体来存储每条记录记录的信息
struct LogEntry{
  char correctkey;
  char inputKey;
  long long timestamp;//时间戳，毫秒级别
};


// 解析日志文件 将每条记录存储到LogEntry实体中
vector<LogEntry> parseLogfile(const string &filename){
  vector<LogEntry>logs;
  // 打开对应路径文件 
  ifstream file(filename);
  string line;

  // 按行读取文件
  while(getline(file,line)){
    LogEntry logentry;
    // 使用 std::stringstream 将读取的行 line 转换为流对象 ss，方便逐个解析字段。
    stringstream ss(line);
    ss>>logentry.correctkey>>logentry.inputKey>>logentry.timestamp;
    logs.push_back(logentry);

  }
  return logs;
  }





  // 计算最长的K连击
  int calculateLongestComb(const vector<LogEntry>&logs){
    int maxComb=0;
    int currentComb=0;
    for(size_t i=0;i<logs.size();i++){
      // 先判断是否触碰正确
      if(logs[i].correctkey==logs[i].inputKey){
        // 如果是第一次击中  则直接开始下一次循环
        if(currentComb==0){
          currentComb=1;
          continue;
        }

        // 否则 检查与上次敲击时间是否小于1s
        if((logs[i].timestamp-logs[i-1].timestamp)<=1000){
          currentComb++;
        }
        // 否则 连击中断
        else{
          currentComb=1;
        }
        maxComb=max(maxComb,currentComb);

      }
      // 如果敲击错误
      else{
        currentComb=0;

      }
    }

    return maxComb;
  }





int main()
{
  // 请在此输入您的代码
  string filename="E:\\Desktop\\log.txt";
  vector<LogEntry> logs=parseLogfile(filename);
  int  a= calculateLongestComb(logs);
  cout<<a<<endl;
  return 0;
}