class Solution {

public:

    void update(vector<int> &a, vector<vector<string> > &ans){

        int n = a.size();

        vector<string> t(n, string(n, '.'));

        for(int i=0; i<n; i++)  t[i][a[i]] = 'Q';

        ans.push_back(t);

    }

    void dfs(int i, int n, vector<int> &a, vector<int> &f_col, vector<int> &f_d1, vector<int> &f_d2, vector<vector<string> > &ans){

        if(i==n){

            update(a, ans);

            return;

        }

        for(int j=0; j<n; j++){

            if(f_col[j])    continue;

            if(f_d1[i-j+n]) continue;

            if(f_d2[i+j])   continue;

            f_col[j] = 1;   f_d1[i-j+n] = 1;    f_d2[i+j] = 1;

            a[i] = j;

            dfs(i+1, n, a, f_col, f_d1, f_d2, ans);

            f_col[j] = 0;   f_d1[i-j+n] = 0;    f_d2[i+j] = 0;

        }

    }

    vector<vector<string> > solveNQueens(int n) {

        vector<int> f_col(n+1, 0);

        vector<int> f_d1(2*n+1, 0);

        vector<int> f_d2(2*n+1, 0);

        vector<int> a(n, 0);

        vector<vector<string> > ans;

        dfs(0, n, a, f_col, f_d1, f_d2, ans);

        return ans;

    }

};
