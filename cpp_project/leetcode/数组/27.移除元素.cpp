/*
 * @Author: Mr.Gan 
 * @Date: 2023-09-16 09:37:06 
 * @Last Modified by:   Mr.Gan 
 * @Last Modified time: 2023-09-16 09:37:06 
 */
// @before-stub-for-debug-begin
#include "commoncppproblem27.h"
#include <string>
// @before-stub-for-debug-end
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int length = nums.size();
        if (!length)
        {
            return length;
        }
        int i = 0;
        while (i < length)
        {
        //走到当前已求得的有效数组长度的最后一个元素的时候  
            if (i == (length - 1))
            {
                //判断最后一个元素是否需去除
                if (nums[i] == val)
                {
                    length--;
                }
        //在此处结束循环
                break;
            }
            if (nums[i] != val)
            {
                i++;
                continue;
            }
            int k = i;
            //此时num[i]需覆盖，将后续元素整体前移一位 数组有效长度减一
            for (; k < length - 1; k++)
            {
                nums[k] = nums[k + 1];
            }
            length--;
        }
        return length;
    }
};
// @lc code=end