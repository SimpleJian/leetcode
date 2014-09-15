class Solution {

public:

    vector<string> dp(vector<int> &f, vector<vector<string> > &ans, string s, int n, unordered_set<string> &dict){

        if(-1^f[n]) return ans[n];

        if(0==n)    return ans[n];

        int f_t = 0;

        vector<string> ans_t;

        for(int i=0; i<n; i++){

            string t = s.substr(i, n-i);

            if(dict.count(t)>0){

                dp(f, ans, s, i, dict);

                if(f[i]){

                    f[n] = 1;

                    if(i==0)    ans_t.push_back(t);

                    for(int j=0; j<ans[i].size(); j++){

                        ans_t.push_back(ans[i][j]+' '+t);

                    }

                }

            }

        }

        return ans[n]=ans_t;

    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {

        vector<int> f(s.length()+1, -1);

        vector<vector<string> > ans(s.length()+1, vector<string>());

        return dp(f, ans, s, s.length(), dict);

    }

};
