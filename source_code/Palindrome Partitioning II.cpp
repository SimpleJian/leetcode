class Solution {

public:

    int dp(vector<vector<int> > &f, int i, int j, string &s){

        if(f[i][j]!=-1) return f[i][j];

        if(i>=j)    return f[i][j] = 1;

        if(s[i]^s[j])   return f[i][j] = 0;

        return f[i][j] = dp(f, i+1, j-1, s);

    }

    int solve(vector<vector<int> > &f, vector<int> &ans, string &s, int len){

        if(ans[len]!=-1)    return ans[len];

        if(len<=1)  return ans[len] = 0;

        int ret = len;

        for(int i=0; i<len; i++){

            if(dp(f, i, len-1, s))  ret = min(ret, solve(f, ans, s, i)+(i>0));

        }

        return ans[len] = ret;

    }

    int minCut(string s) {

        int n = s.length();

        vector<vector<int> > f(n, vector<int>(n, -1));

        vector<int> ans(n+1, -1);

        return solve(f, ans, s, n);

    }

};
