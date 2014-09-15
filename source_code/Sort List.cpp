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

    ListNode *merge(ListNode *p, ListNode * q){

        ListNode *h = new ListNode(0);

        ListNode *cur = h;

        while(1){

            if(NULL==q){

                cur->next = p;

                break;

            }

            if(NULL==p){

                cur->next = q;

                break;

            }

            if(p->val <= q->val){

                cur->next = p;

                p = p->next;

            }

            else{

                cur->next = q;

                q = q->next;

            }

            cur = cur->next;

        }

        return h->next;

    }

    ListNode *sort(ListNode *head, int n){

        if(n<=1)    return head;

        int n1 = n/2;

        int n2 = n-n1;

        ListNode *h1, *h2, *t1;

        h1 = h2 = t1 = head;

        for(int i=0; i<n1-1; i++)   t1 = t1->next;

        h2 = t1->next;

        t1->next = NULL;

        h1 = sort(h1, n1);

        h2 = sort(h2, n2);

        return merge(h1, h2);

    }

    ListNode *sortList(ListNode *head) {

        int n = 0;

        ListNode *p = head;

        while(p){

            n++;

            p = p->next;

        }

        return sort(head, n);

    }

};
