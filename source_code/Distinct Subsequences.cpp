class Solution {

public:

    int dp(int i, int j, string S, string T, vector<vector<int> > &f){

        if(-1!=f[i][j]) return f[i][j];

        if(i<j) return f[i][j] = 0;

        if(j==0)    return f[i][j] = 1;

        int ret = dp(i-1, j, S, T, f);

        if(S[i-1]==T[j-1]){

            ret += dp(i-1, j-1, S, T, f);

        }

        return f[i][j] = ret;

    }

    int numDistinct(string S, string T) {

        int n = S.length();

        int m = T.length();

        vector<vector<int> > f(n+1, vector<int>(m+1, -1));

        return dp(n, m, S, T, f);

    }

};
