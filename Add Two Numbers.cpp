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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l = new ListNode(0);
        ListNode *p = l;
        int a, b, c=0;
        while(NULL != l1 || NULL != l2){
            if(NULL != l1){
                a = l1->val;
                l1 = l1->next;
            }
            else    a = 0;
            if(NULL != l2){
                b = l2->val;
                l2 = l2->next;
            }
            else    b = 0;
            int s = a+b+c;
            p->next = new ListNode(s%10);
            p = p->next;
            c = s/10;
        }
        if(c)   p->next = new ListNode(1);
        return l->next;
    }
};
