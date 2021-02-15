/*
752. 打开转盘锁
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。

 

示例 1:

输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。
示例 2:

输入: deadends = ["8888"], target = "0009"
输出：1
解释：
把最后一位反向旋转一次即可 "0000" -> "0009"。
示例 3:

输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
输出：-1
解释：
无法旋转到目标数字且不被锁定。
示例 4:

输入: deadends = ["0000"], target = "8888"
输出：-1
 

提示：

死亡列表 deadends 的长度范围为 [1, 500]。
目标数字 target 不会在 deadends 之中。
每个 deadends 和 target 中的字符串的数字会在 10,000 个可能的情况 '0000' 到 '9999' 中产生。

解法：
双向BFS，从起点与目标位置交替进行BFS,当两边碰头时即完成搜索
*/

#include<string>
#include<vector>
#include<deque>
#include<set>
#include<unordered_set>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> q1,q2;
        unordered_set<string> visited;
        visited.insert(deadends.begin(),deadends.end());
        if(visited.find("0000") != visited.end())
        {
            return -1;
        }
        //双向遍历
        q1.insert("0000");
        q2.insert(target);
        int res = 0;

        while(!q1.empty() && !q2.empty())
        {
            //优先遍历子集较少的节点
            if(q1.size() > q2.size())
            {
               swap(q1,q2);
            }
        auto temp = q1;
        for(string curr : q1)
        {
            //两边碰头则结束BFS
            if(q2.find(curr) != q2.end())
            {
                return res;
            }

            //删除导致q1迭代器失效，用temp替代q1删除节点
            visited.insert(curr);
            temp.erase(curr);

            //将合法子节点加入set
            for(int j = 0; j < 4; j++)
            {
                string s = curr;
                char ch = (s[j] - '0' + 10 + 1)%10 + '0';
                s[j] = ch;
                if(visited.find(s) == visited.end())
                {
                    temp.insert(s);
                } 

                string s1 = curr;
                ch = (s1[j] - '0' + 10 - 1)%10 + '0';
                s1[j] = ch;
                if(visited.find(s1) == visited.end())
                {
                    temp.insert(s1);
                } 
            }
        }
        //q1、q2交替BFS
        swap(q1,q2);
        swap(q2,temp);
        ++res;
    }
        return -1;
    }
};

int main()
{
   vector<string> v1{"0201","0101","0102","1212","2002"};
   string target{"0202"};
   Solution solution;
   cout << solution.openLock(v1,target) << endl;
   return 0;
}