class Solution {

public:

    vector<vector<int> > dfs(vector<int> &S, int n){

        vector<vector<int> > ret;

        if(n<1){

            ret.push_back(vector<int>());

            return ret;

        }

        int last = S[n-1], cnt = 1;

        for(int i=n-2; i>=0; i--){

            if(S[i]==last)  cnt++;

            else    break;

        }

        vector<vector<int> > pre = dfs(S, n-cnt);

        for(int i=0; i<pre.size(); i++){

            vector<int> t = pre[i];

            ret.push_back(t);

            for(int i=0; i<cnt; i++){

                t.push_back(last);

                ret.push_back(t);

            }

        }

        return ret;

    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {

        sort(S.begin(), S.end());

        return dfs(S, S.size());

    }

};
