/*
498. 对角线遍历
给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

 

示例:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]

解释:

 

说明:

给定矩阵中的元素总数不会超过 100000 。
*/

#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int i = 0; int j = 0;
        vector<int> res;
        if(matrix.size() <= 0)
        return res;
        if(matrix.size() ==1 && matrix[0].size() == 1) {res.push_back(matrix[0][0]); return res;}
        while(i < matrix.size() && j < matrix[0].size())
        {
            if(i == 0 && j == 0)
            {
              res.push_back(matrix[i][j]);  
              //默认向左移动，超出范围时向下移动
              if(j + 1 < matrix[0].size()) j += 1;
              else i += 1;
            }
            else if(i == 0 || j == matrix[0].size() - 1)
            {
                while(j != 0 && i < matrix.size())
                {
                    res.push_back(matrix[i][j]);
                    i += 1; j -= 1;
                }
                //向左下移动，若超出边界则回滚一次迭代
                if(i < matrix.size()) res.push_back(matrix[i][j]);
                else{ i -= 1; j += 1; }
                //默认向下移动，若超出边界则向左移动
                if(i + 1 < matrix.size()) i += 1;
                else j += 1;
            }else if(j == 0 || i == matrix.size() - 1)
            {
                while(i != 0 && j < matrix[0].size())
                {
                    res.push_back(matrix[i][j]);
                    i -= 1;
                    j += 1;
                }
                //向右上移动，若超出边界则回滚一次迭代
                if(j < matrix[0].size()) res.push_back(matrix[i][j]);
                else { i += 1; j -= 1;}
                ////默认向左移动，若超出边界则向下移动
                if(j + 1 < matrix[0].size()) j += 1;
                else i += 1;
            }
        }

        return res;
    }
};