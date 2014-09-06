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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> S;
        S.push(root);
        while(!S.empty()){
            TreeNode *p = S.top();
            S.pop();
            if(NULL==p) continue;
            ans.push_back(p->val);
            S.push(p->left);
            S.push(p->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
