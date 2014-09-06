/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode *root){
        if(NULL==root)  return 0;
        int lH = height(root->left);
        int rH = height(root->right);
        if(lH<0 || rH<0)    return -1;
        if(abs(lH-rH)>1)    return -1;
        return max(lH, rH)+1;
    }
    bool isBalanced(TreeNode *root) {
        return height(root)>=0;
    }
};
