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

    bool isSameTree(TreeNode *p, TreeNode *q) {

        if(NULL==p &&  NULL==q) return 1;

        if(NULL!=p && NULL!=q){

            if(p->val != q->val)    return 0;

            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        }

        else    return 0;

    }

};
