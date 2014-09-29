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

    pair<bool, pair<int,int> > dfs(TreeNode *root){

        if(NULL==root)  return make_pair(1, make_pair(1, 0));

        pair<bool, pair<int,int> > pair_l = dfs(root->left);

        pair<bool, pair<int,int> > pair_r = dfs(root->right);

        pair<bool, pair<int,int> > NO = make_pair(0, make_pair(0,0));

        if(pair_l.first==0 || pair_r.first==0) return NO;

        int low = root->val, high = root->val;

        int low1 = pair_l.second.first, high1 = pair_l.second.second;

        int low2 = pair_r.second.first, high2 = pair_r.second.second;

        if(low1<=high1){

            if(root->val<=high1)    return NO;

            low = min(low, low1);

            high = max(high, high1);

        }

        if(low2<=high2){

            if(root->val>=low2) return NO;

            low = min(low, low2);

            high = max(high, high2);

        }

        return make_pair(1, make_pair(low, high));

    }

    bool isValidBST(TreeNode *root) {

        return dfs(root).first;

    }

};
