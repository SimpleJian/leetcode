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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int len = 0;
        vector<ListNode *> a;
        ListNode *H = new ListNode(0);
        H->next = head;
        ListNode *p;
        for(p=H; NULL != p; p=p->next){
            a.push_back(p);
            len++;
        }
        a[len-n-1]->next = a[len-n-1]->next->next;
        return H->next;
    }
};
