/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution
{
public:
    // 定义比较逻辑，在二维数组中，将身高按从大到小排列。同等身高时，k值较小的排前面
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        // 返回true 则a排b前面 ;否则b排a前面

        return (a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]));
    }
    // 法一：
    // vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    // {

    //     vector<vector<int>> queue;
    //     // 将当前二维数组先按照身高大小 从大到小排序  这样确保了排前面的人的身高大于等于后面的人
    //     sort(people.begin(), people.end(), cmp);
    //     // 进行遍历，根据每个人的k值判断这个人的最终排位
    //     for (int i = 0; i < people.size(); i++)
    //     {
    //         // position表示当前这个人 前面有多少个的身高大于等于它 即它位置
    //         int position = people[i][1];
    //         // 将确定位置的people[i]元素插入在queue中
    //         queue.insert(queue.begin() + position, people[i]);
    //     }
    //     return queue;
    // }

    // 由于vector扩容非常费时，如果插入元素的位置大于预先分配的数组数目，vector底层
    // 会有一个扩容操作，即先申请原先两倍数组的大小，然后再把数据拷贝到一个更大的数组上
    // 所以使用vector（动态数组）来insert，是费时的，插入再拷贝的话，单纯一个插入的操作就是O(n^2)了，
    // 甚至可能拷贝好几次，就不止O(n^2)了。
    // 因此这里使用链表来实现
    // 法二：
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), cmp);
        // list底层是由链表实现  插入效率比vector要高的多
        list<vector<int>> que;
        for (const auto &person : people)
        {
            int position = person[1];
            auto it = que.begin();
            std::advance(it, position);
            que.insert(it, person);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};
// @lc code=end