/*
123. 买卖股票的最佳时机 III
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [3,3,5,0,0,3,1,4]
输出: 6
解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1] 
输出: 0 
解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。
*/


#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
        return 0;
       int total = 0;
       vector<int> left;
       vector<int> right(prices.begin(), prices.end());
       int count = 0;
       int res1 = 0, res2 = 0;
       int left_min = 0, right_min = 0;
       auto tmp = maxProfit_part(right);
       res2 = tmp[0];
       right_min = tmp[1];
       total = res2;
       bool upp = true;
       int sz = prices.size();
       for(int i = 0; i< sz - 1;++i)
       {
           if(prices[i+1] < prices [i])
           {
           upp = false;
           break;
           }
       }
       if(upp)
       {
           return prices[sz - 1] - prices[0]; 
       }
       for(;count < right.size();++count)
       {
           left.push_back(right[count]);
           int new_num = right[count];
           right[count] = __INT_MAX__;
           if(left.size() <= 1)
           {
               res1 = 0;
               left_min = left[0];
           }else if(new_num > left_min)
           {
               res1 = new_num - left_min > res1 ? new_num - left_min : res1;

           }else if(new_num < left_min)
           {
               res1 = maxProfit_part(left)[0];
               left_min = new_num;
           }

            if(res2 == 0)
            {}
            else if(new_num == right_min)
            {
                vector<int> tmp = maxProfit_part(right);
                res2 = tmp[0];
                right_min = tmp[1];
            }

            cout << res1 << "  " << res2 << endl;
            total = total < res1 + res2 ? res1 + res2 : total;

       }

       return total;
    }

     vector<int> maxProfit_part(vector<int>& prices) {
        if(prices.size() <= 1)
        return vector<int>{0,0};
        int left = 0;
        int min = prices[left], res = 0, right_min = 0;


        while(left < prices.size())
        {
            if(prices[left] < min)
            {
                min = prices[left];
            }   
            else if(prices[left] - min > res)
            {
                res = prices[left] - min;
                right_min = min;
            } 
            ++left;
        }
        vector<int> result{res,right_min}; 
        return result; 
    }
};

int main()
{
    Solution solution;
    vector<int> prices{3,2,6,5,0,3};
    cout << solution.maxProfit(prices) << endl;
}