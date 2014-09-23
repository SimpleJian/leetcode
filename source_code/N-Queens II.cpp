class Solution {

public:

    void dfs(int i, int n, int &cnt, vector<int> &f_col, vector<int> &f_d1, vector<int> &f_d2){

        if(i==n){

            cnt++;

            return;

        }

        for(int j=0; j<n; j++){

            if(f_col[j])    continue;

            if(f_d1[i-j+n]) continue;

            if(f_d2[i+j])   continue;

            f_col[j] = 1;   f_d1[i-j+n] = 1;    f_d2[i+j] = 1;

            dfs(i+1, n, cnt, f_col, f_d1, f_d2);

            f_col[j] = 0;   f_d1[i-j+n] = 0;    f_d2[i+j] = 0;

        }

    }

    int totalNQueens(int n) {

        vector<int> f_col(n+1, 0);

        vector<int> f_d1(2*n+1, 0);

        vector<int> f_d2(2*n+1, 0);

        int cnt = 0;

        dfs(0, n, cnt, f_col, f_d1, f_d2);

        return cnt;

    }

};
