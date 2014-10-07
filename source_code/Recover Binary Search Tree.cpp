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

    void dfs(TreeNode *root, TreeNode *&pre, TreeNode *&a, TreeNode *&b){

        if(!root)   return;

        dfs(root->left, pre, a, b);

        if(pre && pre->val > root->val){

            if(!a)  a = pre;

            b = root;

        }

        pre = root;

        dfs(root->right, pre, a, b);

    }

    void recoverTree(TreeNode *root) {

        if(NULL==root)  return;

        TreeNode *a, *b, *pre;

        a = pre = NULL;

        dfs(root, pre, a, b);

        swap(a->val, b->val);

    }

};
