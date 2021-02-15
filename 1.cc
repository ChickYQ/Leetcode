/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/


#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int,int> index_map;
        int index = 0;
        for(auto a : nums)
        {
            index_map.insert({a,index++});
        }
        sort(nums.begin(),nums.end());
        int first = 0, last = nums.size()-1;
        while(true)
        {
            if(nums[first]+nums[last]>target)
            {
                --last;
                continue;
            }
            if(nums[first]+nums[last]<target)
            {
                ++first;
                continue;
            }
            if(nums[first]+nums[last]==target)
            {
                int in1,in2;
                auto iter = index_map.equal_range(nums[first]);
                in1 = iter.first ->second;
                auto tmp = (--iter.second) ->second;
                if( tmp < iter.first ->second)
                {
                    in1 = tmp;
                }
                iter = index_map.equal_range(nums[last]);
                in2 = iter.first ->second;
                tmp = (--iter.second) ->second;
                if( tmp > iter.first ->second)
                {
                    in2 = iter.second ->second;
                }
                return vector<int>{in1,in2};
            }
        }
    }
};