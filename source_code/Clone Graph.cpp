/**

 * Definition for undirected graph.

 * struct UndirectedGraphNode {

 *     int label;

 *     vector<UndirectedGraphNode *> neighbors;

 *     UndirectedGraphNode(int x) : label(x) {};

 * };

 */

class Solution {

public:

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if(NULL==node)  return NULL;

        queue<UndirectedGraphNode*> Q;

        map<UndirectedGraphNode*, UndirectedGraphNode*> f;

        UndirectedGraphNode *u, *v;

        UndirectedGraphNode *h = new UndirectedGraphNode(node->label);

        f[node] = h;

        Q.push(node);

        while(!Q.empty()){

            u = Q.front();

            Q.pop();

            for(auto it = u->neighbors.begin(); it!=u->neighbors.end(); it++){

                v = *it;

                if(f.count(v)==0){

                    f[v] = new UndirectedGraphNode(v->label);

                    Q.push(v);

                }

                f[u]->neighbors.push_back(f[v]);

            }

        }

        return h;

    }

};
