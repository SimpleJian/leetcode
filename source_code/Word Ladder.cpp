class Solution {

public:

    int ladderLength(string start, string end, unordered_set<string> &dict) {

        map<string, int> d;

        queue<string> Q;

        d[start] = 1;

        Q.push(start);

        while(!Q.empty() && d.count(end)==0){

            string u = Q.front();

            Q.pop();

            for(int i=0; i<u.length(); i++){

                for(char c = 'a'; c<='z'; c++){

                    if(u[i]==c) continue;

                    string v = u;

                    v[i] = c;

                    if(dict.count(v)==0)    continue;

                    if(d.count(v)==0){

                        d[v] = d[u] + 1;

                        Q.push(v);

                    }

                }

            }

        }

        if(d.count(end)==0) return 0;

        return d[end];

    }

};
