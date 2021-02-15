#include<vector>
#include<algorithm>

/*56. 合并区间
给出一个区间的集合，请合并所有重叠的区间。

 

示例 1:

输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: intervals = [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。

 

提示：

intervals[i][0] <= intervals[i][1]
*/
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> curr = intervals[0];
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i][0] <= curr[1])
            {
              if(intervals[i][1] > curr[1]) curr[1] = intervals[i][1];
            }else{ res.push_back(curr); curr = intervals[i];}
        }
        res.push_back(curr);
        return res;
    }
};

