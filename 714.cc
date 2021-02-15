/*
714. 买卖股票的最佳时机含手续费
给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

示例 1:

输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
输出: 8
解释: 能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
注意:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
*/

#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() <= 1)
        return 0;
        int left = 0;
        //res为一次交易，total为总的收益,所有成为min的值加上fee
        int min = prices[left] + fee, res = 0, total = 0;


        while(left < prices.size())
        {
            //如果出现更小的值，卖出之前的股票
            if(prices[left] + fee < min)
            {
                min = prices[left] + fee;
                total += res;
                res = 0;
            }   
            //如果能卖出更大的值，则更新res
            else if(prices[left] - min > res)
            {
                res = prices[left] - min;

            }
            //不能卖出更大的值，卖出之前的股票，将当前值设为min
            else if(prices[left] - min < res)
            {               
                if(prices[left] + fee - min > res)
                //不成为新min值的条件，避免两次交易的利润低于一次交易的利润，此时什么都不做，保留res
                {}
                else
                {
                    total += res;
                    res = 0;
                    min = prices[left] + fee;
                }
                
            }
            ++left;
        } 
        return total + res; 
    }
};