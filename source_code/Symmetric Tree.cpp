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

    bool dfs(TreeNode *r1, TreeNode *r2){

        if(NULL==r1 && NULL==r2)    return 1;

        if(NULL==r1 || NULL==r2)    return 0;

        return (r1->val==r2->val) && dfs(r1->left, r2->right) && dfs(r1->right, r2->left);

    }

    bool isSymmetric(TreeNode *root) {

        return dfs(root, root);

    }

};
