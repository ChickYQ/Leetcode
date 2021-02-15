/*
34. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

*/


#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
        return vector<int>(2,-1);
        int res = find(nums,0,nums.size()-1,target);
        if(res == -1)
        {
            return vector<int>(2,-1);
        }
        int min = res, max = res;
        while(min >= 0 && nums[min] == target )
            --min;
        while( max < nums.size() && nums[max] == target)
            ++max;
        return vector<int>{min+1,max-1};

    }

    int find(vector<int>& nums, int begin, int end, int target)
    {
        if(begin == end)
        {
            if(nums[begin] != target)
            {
                return -1;
            }else
            {
                return begin;
            }
        }

        int mid = (begin + end)/2;
        if(nums[mid] == target)
        return mid;
        if(nums[mid] < target)
        {
            return find(nums,mid+1,end,target);
        }else
        {
            return find(nums,begin,mid,target);
        }
    }
};