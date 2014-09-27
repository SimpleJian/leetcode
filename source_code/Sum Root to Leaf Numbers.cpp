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

    void dfs(int pre, TreeNode *r, int &ans){

        pre = 10*pre + r->val;

        if(NULL==r->left && NULL==r->right){

            ans += pre;

            return;

        }

        if(NULL!=r->left)   dfs(pre, r->left, ans);

        if(NULL!=r->right)  dfs(pre, r->right, ans);

    }

    int sumNumbers(TreeNode *root) {

        int ans=0;

        if(NULL==root)  return 0;

        dfs(0, root, ans);

        return ans;

    }

};
