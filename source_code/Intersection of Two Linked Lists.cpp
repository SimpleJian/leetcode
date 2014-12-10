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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lenA = 0;

        int lenB = 0;

        ListNode *p;

        for(p=headA; p; p=p->next)  lenA++;

        for(p=headB; p; p=p->next)  lenB++;

        while(lenA>0 && lenB>0){

            if(lenA == lenB){

                if(headA == headB)    return headA;

                else{

                    headA = headA->next, lenA--;

                    headB = headB->next, lenB--;

                }

            }

            else if(lenA > lenB)    headA = headA->next, lenA--;

            else    headB = headB->next, lenB--;

        }

        return NULL;

    }

};
