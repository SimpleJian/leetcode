/**

 * Definition for binary tree with next pointer.

 * struct TreeLinkNode {

 *  int val;

 *  TreeLinkNode *left, *right, *next;

 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}

 * };

 */

class Solution {

public:

    void connect(TreeLinkNode *root) {

        if(NULL==root)  return;

        TreeLinkNode *last = root;

        TreeLinkNode *cur;

        queue<TreeLinkNode *> Q;

        Q.push(root);

        while(!Q.empty()){

            cur = Q.front();

            Q.pop();

            last->next = cur;

            last = cur;

            if(NULL!=cur->left) Q.push(cur->left);

            if(NULL!=cur->right)    Q.push(cur->right);

        }

        cur = root;

        while(NULL!=cur){

            cur->next = NULL;

            if(NULL!=cur->right)    cur = cur->right;

            else    cur = cur->left;

        }

    }

};
