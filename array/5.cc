/*
5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。

 

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
示例 3：

输入：s = "a"
输出："a"
示例 4：

输入：s = "ac"
输出："a"
 

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母（大写和/或小写）组成
*/

#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        for(int i = 0; i < s.size(); ++i)
        {
            for(int j = s.size() - 1; j >= i; --j)
            {
                // 找到可能的起点和终点，开始验证
                if(s[i] == s[j])
                {
                    int curr_i = i; int curr_j = j; bool update = true;
                    //如果当前子串长度小于结果，则break
                    if(j - i + 1 < res.size()) break;
                    while(curr_i <= curr_j)
                    {
                       if(s[curr_i] != s[curr_j]) {update = false; break; }
                        ++curr_i; --curr_j;
                    }
                    //是回文子串则更新结果
                    if(update)
                    {
                        string curr = s.substr(i,j-i+1);
                        if(curr.size() > res.size()) res = curr;
                    }
                    
                }
            }
        }
        return res;
    }
};

//动态规划法
class Solution2 {
public:
    string longestPalindrome(string s) {
        int maxlen = 1, max_i = 0, max_j = 0;
        // i,j为起点和终点，值为是否为一个回文子串
        bool dp[1000][1000];
        //初始化
        for(int i = 0; i<s.size() -1; ++ i) {dp[i][i] = true;dp[i][i+1] = (s[i] == s[i+1]);}
        int size = s.size() - 1;
        dp[size][size] = true;
        //起点从后往前推（因为计算当前值依赖于i+1的值）
        //状态转移方程dp[i][j] = (dp[i+1][j-1] && s[i] == s[j])，子串是回文，且扩充的左右
        //字符相等
        for(int i = s.size() - 1; i >=0; --i)
        {
            for(int j = i + 1 ; j < s.size()  ; ++j)
            {
                if(j == i + 1) dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
                if(dp[i][j]){
                    if(j - i + 1 > maxlen){max_i =i;max_j = j; maxlen = j - i +1;}
                }
            }
           
        }
        return s.substr(max_i, maxlen);
    }
};
