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

    vector<int> inorderTraversal(TreeNode *root) {

        stack<TreeNode*> path;

        vector<int> ans;

        while(!path.empty() || NULL!=root){

            if(NULL!=root){

                path.push(root);

                root = root->left;

            }

            else{

                root = path.top();

                path.pop();

                ans.push_back(root->val);

                root = root->right;

            }

        }

        return ans;

    }

};
