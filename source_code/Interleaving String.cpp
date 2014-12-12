class Solution {

public:

    bool dfs(string s1, string s2, string s3, int i, int j, vector<vector<int> > &f){

        if(f[i][j] != -1)   return f[i][j];

        if(i==0 && j==0)    return f[i][j] = 1;

        bool t1=0, t2=0;

        if(i>0 && s1[i-1]==s3[i+j-1])   t1 = dfs(s1, s2, s3, i-1, j, f);

        if(j>0 && s2[j-1]==s3[i+j-1])   t2 = dfs(s1, s2, s3, i, j-1, f);

        return f[i][j] = t1 || t2;

    }

    bool isInterleave(string s1, string s2, string s3) {

        int n1 = s1.length();

        int n2 = s2.length();

        if(n1+n2 != s3.length())    return 0;

        vector<vector<int> > f(n1+1, vector<int>(n2+1, -1));

        return dfs(s1, s2, s3, n1, n2, f);

    }

};
