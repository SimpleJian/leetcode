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
    ListNode *partition(ListNode *head, int x) {
        int n = 0;
        vector<int> a;
        ListNode *p = head;
        while(NULL != p){
            int v = p->val;
            if(v<x) a.push_back(v), n++;
            p = p->next;
        }
        p = head;
        while(NULL != p){
            int v = p->val;
            if(v>=x)    a.push_back(v), n++;
            p = p->next;
        }
        p = head;
        for(int i=0; i<n; i++, p = p->next){
            p->val = a[i];
        }
        return head;
    }
};
