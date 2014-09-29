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

    TreeNode *dfs(vector<int> &pre, vector<int> &in, int low_pre, int high_pre, int low_in, int high_in){

        if(low_pre>high_pre)    return NULL;

        TreeNode *root = new TreeNode(pre[low_pre]);

        int mid;

        for(mid=low_in; mid<=high_in; mid++){

            if(in[mid]==pre[low_pre])   break;

        }

        root->left = dfs(pre, in, low_pre+1, low_pre+1+mid-1-low_in, low_in, mid-1);

        root->right = dfs(pre, in, low_pre+1+mid-1-low_in+1, high_pre, mid+1, high_in);

        return root;

    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

        return dfs(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);

    }

};
