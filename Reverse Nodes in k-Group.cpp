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
    ListNode *reverseKGroup(ListNode *head, int k) {
        int n=0;
        ListNode *p;
        for(p=head; NULL!=p; p=p->next) n++;
        if(0==n || 1==k)    return head;
        n /= k;
        ListNode *H = new ListNode(0);
        H->next = head;
        ListNode *a, *b, *c, *d;
        ListNode *pre, *nxt;
        a = H;
        for(int i=0; i<n; i++){
            c = a;
            for(int j=0; j<k; j++){
                c = c->next;
            }
            b = a->next;
            d = c->next;
            
            pre = d;
            p = b;
            for(int j=0; j<k; j++){
                nxt = p->next;
                p->next = pre;
                pre = p;
                p = nxt;
            }
            a->next = c;
            a = b;
        }
        return H->next;
    }
};
