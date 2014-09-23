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

    ListNode *swapPairs(ListNode *head) {

        if(NULL==head)  return head;

        ListNode *h = new ListNode(0);

        h->next = head;

        ListNode *p = h, *t;

        while(NULL != p->next && NULL != p->next->next){

            t = p->next;

            p->next = p->next->next;

            t->next = p->next->next;

            p->next->next = t;

            p = p->next->next;

        }

        return h->next;

    }

};
