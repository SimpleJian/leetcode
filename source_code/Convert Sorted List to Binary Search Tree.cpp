/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

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

    TreeNode *solve(vector<int> &a, int low, int high){

        if(low>high)    return NULL;

        int mid = (low+high)>>1;

        TreeNode *r = new TreeNode(a[mid]);

        TreeNode *L = solve(a, low, mid-1);

        TreeNode *R = solve(a, mid+1, high);

        r->left = L;

        r->right = R;

        return r;

    }

    TreeNode *sortedListToBST(ListNode *head) {

        vector<int> a;

        while(NULL!=head){

            a.push_back(head->val);

            head = head->next;

        }

        return solve(a, 0, a.size()-1);

    }

};
