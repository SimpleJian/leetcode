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
    int check(TreeNode *root, int &ans){
        if(NULL == root)    return 0;
        int lSum = check(root->left, ans);
        int rSum = check(root->right, ans);
        int t = std::max(lSum, rSum);
        t = std::max(t, 0);
        ans = std::max(ans, (root->val)+max(0,lSum)+max(0,rSum));
        return t+(root->val);
    }
    int maxPathSum(TreeNode *root) {
        int ans = root->val;
        check(root, ans);
        return ans;
    }
};
