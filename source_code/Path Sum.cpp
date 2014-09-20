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

    bool hasPathSum(TreeNode *root, int sum) {

        if(NULL==root)  return 0;

        if(root->left==NULL && root->right==NULL) return sum==root->val;

        int s = sum - root->val;

        return hasPathSum(root->left, s) | hasPathSum(root->right, s);

    }

};
