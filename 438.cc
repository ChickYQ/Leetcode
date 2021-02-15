/*
438. 找到字符串中所有字母异位词
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
示例 1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 示例 2:

输入:
s: "abab" p: "ab"

输出:
[0, 1, 2]

解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

解法：
双指针滑动窗口，右指针增大窗口，更新状态，当窗口内状态不满足，移动左指针缩小窗口，更新状态

*/


#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;
        if(p.size() > s.size() || s.size() == 0)
            return res;
        unordered_map<char,int> dict;
        //保存每个字符需要的数量
        for(char ch : p)
        {
            ++dict[ch];
        }
        int left = 0, right = 0;
        while(right < s.size())
        {
            //超过所需数量或不需要该字符时
            if(--dict[s[right]] < 0)
            {
                //缩小窗口到重复字符/不需要字符的下一处，并将移除窗口的字符需求添加回来
                while(s[left] != s[right])
                {
                    ++dict[s[left++]];
                }
                ++dict[s[left++]]; 
            }
            //满足条件
            if(right - left + 1 == p.size())
            {
                res.push_back(left);
                ++dict[s[left++]];
            }
            //增大窗口
            ++right;
        }
        return res;
    }
};