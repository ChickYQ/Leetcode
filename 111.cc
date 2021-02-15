/*
111. 二叉树的最小深度
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。


示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：2
示例 2：

输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
 

提示：

树中节点数的范围在 [0, 105] 内
-1000 <= Node.val <= 1000

解法: BFS
*/


#include<queue>
#include<set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int minDepth(TreeNode* root) {

        queue<TreeNode*> Queue;
        set<TreeNode*> visited;
        if(root == nullptr)
        {
            return 0;
        }
        Queue.push(root);
        visited.insert(root);
        int res = 0;

        while(Queue.size() > 0)
        {
            int num = Queue.size();
            for(int i = 0; i<num; ++i)
            {
                TreeNode *curr = Queue.front();
                Queue.pop();
                visited.insert(curr);
                if(curr -> left == nullptr && curr -> right == nullptr)
                {
                    ++res;
                    return res;
                }
                if(curr -> left != nullptr && visited.count(curr -> left) <= 0)
                {
                    Queue.push(curr -> left);
                }
                if(curr -> right != nullptr && visited.count(curr -> right) <= 0)
                {
                    Queue.push(curr -> right);
                }
            }
            ++res;
        }

    return res;

    }
};