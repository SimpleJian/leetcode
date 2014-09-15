class Solution {

public:

    bool dp(vector<int> &f, string s, int n, unordered_set<string> &dict){

        if(-1^f[n]) return f[n];

        if(0==n)    return f[n] = 1;

        int ans = 0;

        for(int i=0; i<n; i++){

            string t = s.substr(i, n-i);

            if(dict.count(t)>0)

                ans |= dp(f, s, i, dict);

        }

        return f[n] = ans;

    }

    bool wordBreak(string s, unordered_set<string> &dict) {

        vector<int> f(s.length()+1, -1);

        return dp(f, s, s.length(), dict);

    }

};
