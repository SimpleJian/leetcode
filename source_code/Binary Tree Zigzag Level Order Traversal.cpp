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

    void dfs(int depth, TreeNode *root, vector<vector<int> > &ans){

        if(NULL==root)  return;

        if(ans.size()<depth+1)  ans.push_back(vector<int>());

        ans[depth].push_back(root->val);

        dfs(depth+1, root->left, ans);

        dfs(depth+1, root->right, ans);

    }

    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {

        vector<vector<int> > ans;

        dfs(0, root, ans);

        for(int i=1; i<ans.size(); i+=2){

            reverse(ans[i].begin(), ans[i].end());

        }

        return ans;

    }

};
