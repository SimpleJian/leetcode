/**

 * Definition for singly-linked list with a random pointer.

 * struct RandomListNode {

 *     int label;

 *     RandomListNode *next, *random;

 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}

 * };

 */

class Solution {

public:

    RandomListNode *copyRandomList(RandomListNode *head) {

        map<RandomListNode *, int> id;

        RandomListNode *p = head;

        RandomListNode *h = new RandomListNode(0), *q=h;

        int n = 0;

        while(p){

            id[p] = n++;

            q->next = new RandomListNode(p->label);

            q = q->next;

            p = p->next;

        }

        map<int, RandomListNode *> pt;

        q = h->next;

        for(int i=0; i<n; i++){

            pt[i] = q;

            q = q->next;

        }

        p = head;

        q = h->next;

        while(p){

            if(p->random){

                int i = id[p->random];

                q->random = pt[i];

            }

            else    q->random = NULL;

            p = p->next;

            q = q->next;

        }

        return h->next;

    }

};
