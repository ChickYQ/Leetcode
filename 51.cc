/*
51. N 皇后
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



上图为 8 皇后问题的一种解法。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

 

示例：

输入：4
输出：[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
 

提示：

皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

解法：
回溯法
利用mark保存被选择过的位置

*/


#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> path;
        vector<int> mark(n, 0);
        back(path, n, mark);
        return res;
    }
    vector<vector<string>> res;
    void back(vector<int> &path, int n, vector<int>& mark)
    {
        if(path.size() == n)
        {
            vector<string> v;
            for(int q : path)
            {
                string s(n, '.');
                s = s.replace(q, 1, "Q");
                v.push_back(s);
            }
            res.push_back(v);
        }

        for(int i = 0; i< n; ++i)
        {
            if(mark[i] != -1)
            {
                bool legal = true;
                for(int j = 0; j < path.size();++j)
                {
                    if(path.size() - j == -(i - path[j])||path.size() - j == i - path[j])
                    {
                        legal = false;
                        break;
                    }
                }
                if(legal)
                {
                    path.push_back(i);
                    mark[i] = -1;
                    back(path, n, mark);
                    path.pop_back();
                    mark[i] = 0;
                }
            }
        }

    }
};

int main()
{
    Solution solution;
    solution.solveNQueens(4);
    return 0;
}