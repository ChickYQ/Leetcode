#include<vector>
#include<array>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() <= 1)
        return 0;
        int n = prices.size();
        if(k >= n/2)
        k = n/2;
        std::vector<std::vector<std::vector<int>>> dp(n);
        for (int i = 0; i < n; i++)
        {
            dp[i].resize(k + 1);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                dp[i][j].resize(2);
            }
        }
         for(int j = 0; j <= k; ++j)
        {
            dp[1][j][0] =  0;
            dp[1][j][1] =  -prices[0];
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = k ; j >= 1; --j)
            {
                if(i == 0)
                {
                     dp[i][j][0] = 0;
                     dp[i][j][1] = -prices[i];
                }
                else{
                dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1],dp[i-1][j-1][0] - prices[i]);
                }
                cout << "dp" << i << " " << j <<" 0 " << " " << dp[i][j][0] << endl;
                cout << "dp" << i << " " << j <<" 1 " << " " << dp[i][j][1] << endl;
               
            }
        }
        int res = dp[n-1][k][0];
        
        return res;

        

    }
};

int main()
{
    Solution solution;
    vector<int> prices{3,2,6,5,0,3};
    cout << solution.maxProfit(2, prices) << endl;

    return 0;
}