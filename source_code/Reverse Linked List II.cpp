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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *H = new ListNode(0);
        H->next = head;
        ListNode *a, *b, *c, *d, *p;
        ListNode *pre = NULL, *nxt;
        int i;
        for(p=H, i=0; NULL != p; p=nxt, i++){
            if(i+1==m){
                a = p;
                b = p->next;
            }
            if(i==n){
                c = p;
                d = p->next;
            }
            if(i>=m && i<=n){
                nxt = p->next;
                p->next = pre;
                pre = p;
            }
            else    nxt = p->next;
        }
        a->next = c;
        b->next = d;
        return H->next;
    }
};
