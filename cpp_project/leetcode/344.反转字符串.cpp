/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    void swap(char &a,char &b){
        char temp;
        temp = a;
        a = b;
        b = temp;
    }
    void reverseString(vector<char>& s) {
        if(s.size()<=1){
            return;
        }
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            swap(s[i], s[j]);
            j--;
            i++;    
        }
    }
};
// @lc code=end

