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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *l = new ListNode(0);
        ListNode *p = l;
        while(NULL != l1 || NULL != l2){
            if(NULL==l1){
                    p->next = l2;
                    l2 = l2->next;
            }
            else if(NULL==l2){
                    p->next = l1;
                    l1 = l1->next;
            }
            else{
                if((l1->val) < (l2->val)){
                    p->next = l1;
                    l1 = l1->next;
                }
                else{
                    p->next = l2;
                    l2 = l2->next;
                }
            }
            p = p->next;
        }
        return l->next;
    }
};
