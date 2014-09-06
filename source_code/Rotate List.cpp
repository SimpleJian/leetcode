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
    ListNode *rotateRight(ListNode *head, int k) {
        if(NULL == head)    return head;
        int n = 0;
        ListNode *p = head;
        while(NULL != p){
            n++;
            p = p->next;
        }
        k = (n-k%n)%n;
        if(0==k)    return head;
        p = head;
        for(int i=0; i<k-1; i++)    p = p->next;
        ListNode *newHead = p->next;
        p->next = NULL;
        p = newHead;
        while(NULL != p->next)  p = p->next;
        p->next = head;
        return newHead;
    }
};
