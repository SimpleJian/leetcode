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

    void dfs(TreeNode *r, int depth, vector<vector<int> > &ans){

        if(NULL==r) return;

        if(ans.size()<depth+1)  ans.push_back(vector<int>());

        ans[depth].push_back(r->val);

        dfs(r->left, depth+1, ans);

        dfs(r->right, depth+1, ans);

    }

    vector<vector<int> > levelOrder(TreeNode *root) {

        vector<vector<int> > ans;

        dfs(root, 0, ans);

        return ans;

    }

};
