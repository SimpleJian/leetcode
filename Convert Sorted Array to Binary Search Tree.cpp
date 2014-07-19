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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int n = num.size();
        if(0==n)    return NULL;
        int mid = n/2;
        vector<int> leftNum(num.begin(), num.begin()+mid);
        vector<int> rightNum(num.begin()+mid+1, num.end());
        TreeNode *root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST(leftNum);
        root->right = sortedArrayToBST(rightNum);
        return root;
    }
};
