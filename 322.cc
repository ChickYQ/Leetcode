/*322. 零钱兑换
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

你可以认为每种硬币的数量是无限的。

 

示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
示例 2：

输入：coins = [2], amount = 3
输出：-1
示例 3：

输入：coins = [1], amount = 0
输出：0
示例 4：

输入：coins = [1], amount = 1
输出：1
示例 5：

输入：coins = [1], amount = 2
输出：2
 

提示：

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104


dp参考：https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-by-leetcode-solution/
贪心 + dfs 参考：https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/
*/
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
   /* int coinChange(vector<int>& coins, int amount) { 
        if(amount <= 0)
        return 0;
        dict.resize(amount+1);
        return dp(amount,coins);
    }*/
    /*
    dp自顶向下解法
    */
    vector<int> dict;
    int dp(int n,vector<int>& coins)
    {
        if(n < 0)
        return -1;
        if(n == 0)
        return 0;
        if(dict[n] != 0)
        return dict[n];
        int res = __INT_MAX__;
        for(int coin : coins)
        {
            int sub = dp(n - coin, coins);
            if(sub < 0)continue;
            res = min(res,sub + 1);
        }
        if(res ==  __INT_MAX__ )
            dict[n] = -1;
        else
            dict[n] = res;   
        return dict[n];        
    }

    /*
    贪心算法 + dfs

    贪心
11. 想要总硬币数最少，肯定是优先用大面值硬币，所以对 coins 按从大到小排序
12. 先丢大硬币，再丢会超过总额时，就可以递归下一层丢的是稍小面值的硬币

乘法对加法的加速
21. 优先丢大硬币进去尝试，也没必要一个一个丢，可以用乘法算一下最多能丢几个

k = amount / coins[c_index] 计算最大能投几个
amount - k * coins[c_index] 减去扔了 k 个硬币
count + k 加 k 个硬币

如果因为丢多了导致最后无法凑出总额，再回溯减少大硬币数量
最先找到的并不是最优解
31. 注意不是现实中发行的硬币，面值组合规划合理，会有奇葩情况
32. 考虑到有 [1,7,10] 这种用例，按照贪心思路 10 + 1 + 1 + 1 + 1 会比 7 + 7 更早找到
33. 所以还是需要把所有情况都递归完

ans 疯狂剪枝
41. 贪心虽然得不到最优解，但也不是没用的
42. 我们快速算出一个贪心的 ans 之后，虽然还会有奇葩情况，但是绝大部分普通情况就可以疯狂剪枝了
  */
void coinChange(vector<int>& coins, int amount, int c_index, int count, int& ans)
{
    if(amount ==0)
    {
        ans = min(ans, count);
        return;
    }

    if(c_index ==coins.size())
        return;

    for(int k = amount/coins[c_index]; k>=0 && k + count < ans; --k)
    {
        coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
    }
}

 int coinChange(vector<int>& coins, int amount) { 
        if(amount <= 0)
        return 0;
        sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        coinChange(coins, amount, 0, 0, ans);

        return ans == INT_MAX ? -1 : ans;
    }

};

int main()
{
    Solution solution;
    vector<int> coins{1,2,5};
    cout << solution.coinChange(coins,11) << endl;
    return 0;
}