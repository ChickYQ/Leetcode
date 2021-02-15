/*
面试题 01.07. 旋转矩阵
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

不占用额外内存空间能否做到？

 

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
/*
思路，对第i行每一个值，变换到旋转后的位置， 转换公式为 new_i = old_j ,new_j = size - old_i - 1
新位置的坐标作为下一个旋转的目标位置，转换4次后回到原点
处理完外层数据，再对内层矩阵进行旋转
*/

/*
另一种思路 ： 先将矩阵水平翻转，即最后一行换到第一行，依次类推；
再对矩阵做对角线翻转，即行列互换，swap(m[i][j],m[j][i]),即可得到结果。
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int size = matrix.size(); 
        int n = size; int m = size;
        //每次处理完外层数据，矩阵未处理行列数减少2，需加上原来的i值才表示为真实的坐标
        for(int i = 0;i <= n - 2 + i; ++i)
        {
            for(int j = i; j <= m - 2 + i; ++j)
            {
              cout << "(" << i << " , " << j << ")" << endl;
                int curr_i = i;
                int curr_j = j;
                int curr = matrix[curr_i][curr_j];
                for(int k = 1; k <= 4; ++k)
                {
                    int new_i = curr_j;
                    int new_j = size - curr_i - 1;
                    int temp = matrix[new_i][new_j];
                    matrix[new_i][new_j] = curr;
                    curr = temp;
                    curr_i = new_i;
                    curr_j = new_j;
                }
            }
            n -= 2; m -= 2;
        }
        
    }
};

int main()
{
  vector<vector<int>> matrix = {{ 5, 1, 9,11},
  { 2, 4, 8,10},
  {13, 3, 6, 7},
  {15,14,12,16}};

  Solution solution;
  solution.rotate(matrix);

  return 0;
}