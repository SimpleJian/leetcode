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

    pair<TreeNode *, TreeNode *> solve(TreeNode *r){

        if(NULL==r->left && NULL==r->right) return make_pair(r, r);

        if(NULL!=r->left && NULL!=r->right){

            pair<TreeNode *, TreeNode *> L = solve(r->left);

            pair<TreeNode *, TreeNode *> R = solve(r->right);

            r->left = NULL;

            r->right = L.first;

            L.second->right = R.first;

            return make_pair(r, R.second);

        }

        if(NULL!=r->left){

            pair<TreeNode *, TreeNode *> L = solve(r->left);

            r->left = NULL;

            r->right = L.first;

            return make_pair(r, L.second);

        }

        else{

            pair<TreeNode *, TreeNode *> R = solve(r->right);

            r->left = NULL;

            r->right = R.first;

            return make_pair(r, R.second);

        }

    }

    void flatten(TreeNode *root) {

        if(NULL==root)  return;

        solve(root);

    }

};
