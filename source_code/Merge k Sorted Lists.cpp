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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<int> val;
        ListNode *p;
        int n = lists.size();
        for(int i=0; i<n; i++){
            for(p=lists[i]; NULL != p; p=p->next){
                val.push_back(p->val);
            }
        }
        sort(val.begin(), val.end());
        ListNode *H = new ListNode(0);
        p = H;
        for(int i=0; i<val.size(); i++){
            p->next = new ListNode(val[i]);
            p = p->next;
        }
        return H->next;
    }
};
