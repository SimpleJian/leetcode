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
    ListNode *deleteDuplicates(ListNode *head) {
        if(NULL == head)    return head;
        ListNode *p = head;
        map<int, int> m;
        while(NULL != p){
            int x = p->val;
            if(m.end()!=m.find(x))    m[x]++;
            else    m[x] = 1;
            p = p->next;
        }
        ListNode *H = new ListNode(0);
        H->next = head;
        p = H;
        while(NULL != p->next){
            int x = p->next->val;
            if(m[x]>1){
                p->next = p->next->next;
            }
            else    p = p->next;
        }
        return H->next;
    }
};
