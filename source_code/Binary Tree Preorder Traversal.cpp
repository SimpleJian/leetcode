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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> nodeStack;
        vector<int> ans;
        nodeStack.push(root);
        while(!nodeStack.empty()){
            TreeNode *p = nodeStack.top();
            nodeStack.pop();
            if(NULL == p)   continue;
            ans.push_back(p->val);
            nodeStack.push(p->right);
            nodeStack.push(p->left);
        }
        return ans;
    }
};
