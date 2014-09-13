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

    // insert p->next after q

    void insert(ListNode *p, ListNode *q){

        ListNode *t = p->next;

        p->next = p->next->next;

        t->next = q->next;

        q->next = t;

    }

    ListNode *insertionSortList(ListNode *head) {

        if(NULL==head)  return head;

        ListNode *h = new ListNode(0);

        h->next = head;

        ListNode *cur = head, *p;

        while(cur->next){

            if(cur->next->val >= cur->val)  cur = cur->next;

            else{

                for(p=h; ; p=p->next){

                    if(p->next->val >= cur->next->val){

                        insert(cur, p);

                        break;

                    }

                }

            }

        }

        return h->next;

    }

};
