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

    TreeNode *dfs(vector<int> &in, vector<int> &post, int low_in, int high_in, int low_post, int high_post){

        if(low_in>high_in)  return NULL;

        TreeNode *root = new TreeNode(post[high_post]);

        int mid;

        for(mid=low_in; mid<=high_in; mid++){

            if(in[mid]==post[high_post])    break;

        }

        root->left = dfs(in, post, low_in, mid-1, low_post, mid-1-low_in+low_post);

        root->right = dfs(in, post, mid+1, high_in, mid-low_in+low_post, high_post-1);

        return root;

    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

        return dfs(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);

    }

};
