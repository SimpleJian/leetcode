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

        if(NULL==r->left && NULL==r->right){

            ans = min(ans, pre+1);

            return;

        }

        if(NULL!=r->left)   dfs(pre+1, r->left, ans);

        if(NULL!=r->right)  dfs(pre+1, r->right, ans);

    }

    int minDepth(TreeNode *root) {

        if(NULL==root)  return 0;

        int ans = 0x3f3f3f3f;

        dfs(0, root, ans);

        return ans;

    }

};
