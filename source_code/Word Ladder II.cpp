class Solution {

public:

    vector<vector<string>> getPaths(string u, int x, unordered_map<string, int> &d, unordered_map<string, vector<vector<string>>> &ans){

        if(ans.count(u))    return ans[u];

        if(0==x)    return ans[u] = vector<vector<string>>(1, vector<string>(1, u));

        vector<vector<string>> ansu;

        for(int i=0; i<u.length(); i++){

            string v = u;

            for(int j=0; j<26; j++){

                v[i] = 'a'+j;

                if(d.count(v) && d[v]==x-1){

                    auto ansv = getPaths(v, x-1, d, ans);

                    for(auto it=ansv.begin(); it!=ansv.end(); it++){

                        auto t = *it;

                        t.push_back(u);

                        ansu.push_back(t);

                    }

                }

            }

        }

        return ans[u] = ansu;

    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {

        unordered_map<string, int> d;

        d[start] = 0;

        queue<string> Q;

        Q.push(start);

        while(!Q.empty()){

            string u = Q.front();

            Q.pop();

            for(int i=0; i<u.length(); i++){

                string v = u;

                for(int j=0; j<26; j++){

                    v[i] = 'a'+j;

                    if(dict.count(v) && !d.count(v)){

                        d[v] = d[u]+1;

                        Q.push(v);

                    }

                }

            }

        }

        unordered_map<string, vector<vector<string>>> ans;

        if(d.count(end))    return getPaths(end, d[end], d, ans);

        else    return vector<vector<string>>();

    }

};
