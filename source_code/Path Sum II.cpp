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

    void dfs(int k, int sum, int target, TreeNode *root, vector<int> t, vector<vector<int> > &ans){

        if(NULL==root)  return;

        sum += root->val;

        if(t.size()<k+1)    t.push_back(root->val);

        else    t[k] = root->val;

        if(NULL==root->left && NULL==root->right){

            if(sum==target) ans.push_back(t);

            return;

        }

        dfs(k+1, sum, target, root->left, t, ans);

        dfs(k+1, sum, target, root->right, t, ans);

    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {

        vector<vector<int> > ans;

        vector<int> t;

        dfs(0, 0, sum, root, t, ans);

        return ans;

    }

};
