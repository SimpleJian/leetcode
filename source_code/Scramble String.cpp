class Solution {

public:

    bool solve(string s1, int low1, int high1, string s2, int low2, int high2, vector<vector<vector<int> > > &f){

        if(f[low1][high1][low2] != -1)  return f[low1][high1][low2];

        // pruning when s1[low1...high1]==s2[low2...high2]

        bool yes = 1;

        for(int i=0; i<high1-low1+1; i++){

            if(s1[i+low1]!=s2[i+low2])  yes = 0;

        }

        if(yes) return f[low1][high1][low2] = 1;

        // pruning when impossible

        vector<int> a(128, 0), b(128, 0);

        for(int i=low1; i<=high1; i++)  a[s1[i]]++;

        for(int i=low2; i<=high2; i++)  b[s2[i]]++;

        for(int i=0; i<128; i++)    if(a[i]!=b[i])  return f[low1][high1][low2] = 0;

        if(low1==high1) return f[low1][high1][low2] = s1[low1]==s2[low2];

        // still possible, so...

        for(int i=1; i<high1-low1+1; i++){

            bool t1 = solve(s1, low1, low1+i-1, s2, high2-i+1, high2, f) && solve(s1, low1+i, high1, s2, low2, high2-i, f);

            bool t2 = solve(s1, low1, low1+i-1, s2, low2, low2+i-1, f) && solve(s1, low1+i, high1, s2, low2+i, high2, f);

            if(t1 || t2)  return f[low1][high1][low2] = 1;

        }

        return f[low1][high1][low2] = 0;

    }

    bool isScramble(string s1, string s2) {

        int n = s1.length();

        if(n != s2.length())    return 0;

        vector<vector<vector<int> > > f(n, vector<vector<int> >(n, vector<int>(n, -1)));

        return solve(s1, 0, s1.length()-1, s2, 0, s2.length()-1, f);

    }

};
