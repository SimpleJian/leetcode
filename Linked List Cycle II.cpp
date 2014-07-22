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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        while(NULL!=slow && NULL!=fast){
            slow = slow->next;
            fast = fast->next;
            if(NULL==fast)  return NULL;
            else    fast = fast->next;
            if(slow==fast)  break;
        }
        if(NULL==slow || NULL==fast)    return NULL;
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
