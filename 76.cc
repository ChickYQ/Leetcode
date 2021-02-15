/*
76. 最小覆盖子串
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：

输入：s = "a", t = "a"
输出："a"
 

提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成
 

进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？

解法：双指针滑动窗口，右指针增大窗口，更新状态，当窗口内状态不满足，移动左指针缩小窗口，更新状态
*/


#include<iostream>
#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.size() > s.size() || s.size() == 0)
        return "";
        if(s == t)
        return s;
        //dict 用来判断字符是否需要，dict_copy来保存每个字符的需求数量
        unordered_map<char,int> dict,dict_copy;
         //保存每个字符需要的数量
        for(char ch : t)
        {
            ++dict[ch];
        }
        dict_copy = dict;
        //nums为剩余需要收集的字符个数，当 nums为 0，既收集到需要的所有字符
        int left = 0, right = 0, nums = t.size();
        int res_left = 0, res_right = 0 , min = s.size();
        //先将left置为第一个所需要字符的位置（窗口的左值和右值都应为所需要的字符)
        while(right < s.size())
        {
            if(dict[s[right]] > 0)
            {
                left = right;
                --dict_copy[s[right]];
                --nums;
                break;
            }
            ++right;
        }
         ++right;
         //若第一个字符即为 t,则返回
         string tmp(1,s[left]);
         if(t == tmp)
         return t;
        while(right < s.size())
        {
            /*if(right - left >= min)
            {
                while(dict[s[left]] <= 0 || (dict[s[left]] > 0 && dict_copy[s[left]] < 0))
                {
                    if((dict[s[left]] > 0 && dict_copy[s[left]] < 0))
                         ++dict_copy[s[left]];
                    ++left;
                }
            }*/
            //cout << left << "  " << right << endl;
            //s[right]为所需字符且需求量不为0并且nums为 1 时，窗口满足条件
            if( dict[s[right]] > 0 &&  dict_copy[s[right]] - 1 >= 0 && nums - 1 == 0 )
            {
                 //cout << "part 1"<< endl;
                 //减少需求，减少剩余个数
                --dict_copy[s[right]];
                --nums;
                if(right - left < min)
                {
                    min = right - left;
                    res_left = left;
                    res_right = right;
                }
                //缩小窗口，恢复需求和剩余个数
                ++dict_copy[s[left]];
                ++nums;
                ++left;
                //缩小窗口，使left指向下一个所需字符
                //当dict_copy[s[left]] < 0时，代表窗口内该字符的个数大于需求数
                //应该继续缩小窗口，并增大该字符的需求个数
                while(dict[s[left]] <= 0 || (dict[s[left]] > 0 && dict_copy[s[left]] < 0))
                {
                    if((dict[s[left]] > 0 && dict_copy[s[left]] < 0))
                         ++dict_copy[s[left]];
                    ++left;
                }
            }
            //s[right]为所需字符，但已经达到所需个数
            else if(dict[s[right]] > 0 &&  dict_copy[s[right]] - 1 < 0)
            {
                cout << "part 2"<< endl;
                //该字符已达到目标，不减少剩余字符个数nums
                --dict_copy[s[right]];
                //若窗口边界值相等，缩小窗口使left指向下一所需字符
                if(s[left] == s[right])
                {
                    ++dict_copy[s[left]]; 
                    ++left;
                while(dict[s[left]] <= 0 || (dict[s[left]] > 0 && dict_copy[s[left]] < 0))
                {
                    if((dict[s[left]] > 0 && dict_copy[s[left]] < 0))
                         ++dict_copy[s[left]];
                    ++left;
                }

                }
            }
            //s[right]为所需字符，并且未达到所需个数
            else if(dict[s[right]] > 0 )
            {
                //cout << "part 3"<< endl;
                //减少字符需求，减少剩余个数
                --dict_copy[s[right]];
                --nums;
            }
            //s[right]不是所需字符，什么都不做
            //增加窗口
            ++right;

        }
        if(min == s.size())
        return "";
        return s.substr(res_left, res_right - res_left + 1);
    }
};

int main()
{
    string s = "adobecodebancbbcaa";
    string t = "abc";
    Solution solution;
    cout << solution.minWindow(s,t) << endl;

    return 0;
}