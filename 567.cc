/*
567. 字符串的排列
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False
 

注意：

输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10,000] 之间

解法：
双指针滑动窗口，右指针增大窗口，更新状态，当窗口内状态不满足，移动左指针缩小窗口，更新状态
*/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())
            return false;
        unordered_map<char,int> dict;
        //保存每个字符需要的数量
        for(char ch : s1)
        {
            ++dict[ch];
        }
        int left = 0, right = 0;
        while(right < s2.size())
        {
            //超过所需数量或不需要该字符时
            if(--dict[s2[right]] < 0)
            {
                //缩小窗口到重复字符/不需要字符的下一处，并将移除窗口的字符需求添加回来
                while(s2[left] != s2[right])
                {
                    ++dict[s2[left]];
                    ++left;
                }
                ++dict[s2[left]]; 
                ++left;
            }
            //满足条件
            if(right - left + 1 == s1.size())
                return true;
            //增大窗口
            ++right;
        }
        return false;
    }
};