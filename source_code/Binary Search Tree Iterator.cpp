/**

 * Definition for binary tree

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

class BSTIterator {

private:

    stack<TreeNode *> S;

    TreeNode *cur;

public:

    BSTIterator(TreeNode *root) {

        cur = root;

        pushLeft(cur);

    }



    /** @return whether we have a next smallest number */

    bool hasNext() {

        return cur || !S.empty();

    }



    /** @return the next smallest number */

    int next() {

        cur = S.top();

        S.pop();

        int x = cur->val;

        cur = cur->right;

        pushLeft(cur);

        return x;

    }

    void pushLeft(TreeNode *root){

        while(root){

            S.push(root);

            root = root->left;

        }

    }

};



/**

 * Your BSTIterator will be called like this:

 * BSTIterator i = BSTIterator(root);

 * while (i.hasNext()) cout << i.next();

 */
