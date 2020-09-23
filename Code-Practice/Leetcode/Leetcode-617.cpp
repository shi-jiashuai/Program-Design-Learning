/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        // 深度优先搜索
        if(t1 == nullptr)
        {
            return t2;
        }

        if(t2 == nullptr)
        {
            return t1;
        }

         TreeNode* resTree = new TreeNode(t1->val + t2->val);
         resTree->left = mergeTrees(t1->left, t2->left);
         resTree->right = mergeTrees(t1->right,t2->right);

         return resTree;
    }
};