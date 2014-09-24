class Solution {

public:

    bool dfs(int i, int n, vector<int> &f, vector<int> &ans){

        if(i==n)    return 1;

        int last = ans[i-1];

        for(int j=0; j<n; j++){

            int k = 1<<j;

            int t = last ^ k;

            if(0==f[t]){

                f[t] = 1;

                ans[i] = t;

                if(dfs(i+1, n, f, ans)) return  true;

                f[t] = 0;

            }

        }

    }

    vector<int> grayCode(int n) {

        int cnt = 1<<n;

        vector<int> f(cnt, 0);

        vector<int> ans(cnt, 0);

        f[0] = 1;

        dfs(1, cnt, f, ans);

        return ans;

    }

};
