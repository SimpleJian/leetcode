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

    void solve(int n, vector<int> &f, vector<vector<TreeNode *> > &ans){

        if(f[n])    return;

        f[n] = 1;

        vector<TreeNode *> t;

        if(0==n){

            t.push_back(NULL);

            ans[n] = t;

            return;

        }

        for(int k=0; k<n; k++){

            solve(k, f, ans);

            solve(n-1-k, f, ans);

            for(int i=0; i<ans[k].size(); i++){

                for(int j=0; j<ans[n-1-k].size(); j++){

                    TreeNode *r = new TreeNode(0);

                    r->left = ans[k][i];

                    r->right = ans[n-1-k][j];

                    t.push_back(r);

                }

            }

        }

        ans[n] = t;

    }

    TreeNode* copy_fill(TreeNode *root, int &t){

        if(NULL==root) return   NULL;

        TreeNode *L = copy_fill(root->left, t);

        TreeNode *r = new TreeNode(t++);

        TreeNode *R = copy_fill(root->right, t);

        r->left = L;

        r->right = R;

        return r;

    }

    vector<TreeNode *> generateTrees(int n) {

        vector<int> f(n+1, 0);

        vector<vector<TreeNode *> > ans(n+1, vector<TreeNode*>());

        solve(n, f, ans);

        for(int i=0; i<ans[n].size(); i++){

            int id = 1;

            ans[n][i] = copy_fill(ans[n][i], id);

        }

        return ans[n];

    }

};
