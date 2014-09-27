class Solution {

public:

    void dfs(int i, int n, vector<int> num, vector<int> &t, vector<int> &f, vector<vector<int> > &ans){

        if(i==n){

            ans.push_back(t);

            return;

        }

        for(int k=0; k<n; k++){

            if(f[k])    continue;

            f[k] = 1;

            t[i] = num[k];

            dfs(i+1, n, num, t, f, ans);

            f[k] = 0;

        }

    }

    vector<vector<int> > permute(vector<int> &num) {

        int n = num.size();

        vector<vector<int> > ans;

        vector<int> f(n, 0);

        vector<int> t(n, 0);

        dfs(0, n, num, t, f, ans);

        return ans;

    }

};
