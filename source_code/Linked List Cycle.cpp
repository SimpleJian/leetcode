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

    bool hasCycle(ListNode *head) {

        ListNode *p1, *p2;

        p1 = p2 = head;

        while(true){

            if(NULL==p1)    return 0;

            p1 = p1->next;

            if(NULL==p2 || NULL==p2->next)  return 0;

            p2 = p2->next->next;

            if(p1==p2)  return 1;

        }

    }

};
