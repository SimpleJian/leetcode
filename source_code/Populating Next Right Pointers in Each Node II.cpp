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

        pair<TreeLinkNode *, int> last = make_pair(root, 0);

        pair<TreeLinkNode *, int> cur;

        queue<pair<TreeLinkNode *, int> > Q;

        Q.push(last);

        while(!Q.empty()){

            cur = Q.front();

            Q.pop();

            if(last.second>0 && last.second==cur.second) (last.first)->next = cur.first;

            else    (last.first)->next = NULL;

            last = cur;

            if(NULL!=cur.first->left)   Q.push(make_pair(cur.first->left, cur.second+1));

            if(NULL!=cur.first->right)  Q.push(make_pair(cur.first->right, cur.second+1));

        }

    }

};
