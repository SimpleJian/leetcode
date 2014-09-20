/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

class Solution {

public:

    ListNode *deleteDuplicates(ListNode *head) {

        if(NULL==head)  return head;

        ListNode *p = head;

        int last = p->val;

        while(NULL != p->next){

            if(p->next->val==last)  p->next = p->next->next;

            else{

                p = p->next;

                last = p->val;

            }

        }

        return head;

    }

};
