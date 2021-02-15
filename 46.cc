/*
46. 全排列
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]


思路：
回溯法
for 选择 in 选择列表:
    # 做选择
    将该选择从选择列表移除
    路径.add(选择)
    backtrack(路径, 选择列表)
    # 撤销选择
    路径.remove(选择)
    将该选择再加入选择列表

利用mark_map 来标记已经做出的选择
*/


#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        map<int, int> mark_map;
        back(path,nums,mark_map);
        return res;
    }

    vector<vector<int>> res;
    void back(vector<int>& path, vector<int>& nums, map<int, int>& mark_map)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for(int num : nums)
        {
            if(mark_map[num] != -1)
            {
                mark_map[num] = -1;
                path.push_back(num);
                back(path,nums,mark_map);
                path.pop_back();
                mark_map[num] = 0;
            }
        }
    }
};