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
    ListNode *reverseList(ListNode *head){
        if(NULL == head)    return NULL;
        ListNode *pre=NULL, *p=head, *q=head->next;
        while(NULL != p){
            p->next = pre;
            pre = p;
            p = q;
            if(NULL == p)   break;
            q = q->next;
        }
        return pre;
    }
    void mergeList(ListNode *p, ListNode *q){
        while(NULL != p){
            ListNode *p1 = p->next;
            p->next = q;
            if(NULL == q)   break;
            ListNode *q1 = q->next;
            q->next = p1;
            p = p1;
            q = q1;
        }
    }
    void reorderList(ListNode *head) {
        int n = 0;
        ListNode *p = head;
        while(NULL != p){
            n++;
            p = p->next;
        }
        if(0==n)    return;
        int n1 = (n-1)/2;
        p = head;
        while(n1--) p = p->next;
        ListNode *q = p->next;
        p->next = NULL;
        q = reverseList(q);
        mergeList(head, q);
    }
};
