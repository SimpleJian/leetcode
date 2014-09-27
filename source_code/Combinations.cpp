class Solution {

public:

    void dfs(int depth, int n, int k, int start, vector<int> &t, vector<vector<int> > &ans){

        if(depth==k){

            ans.push_back(t);

            return;

        }

        for(int i=start; i<=n; i++){

            t[depth] = i;

            dfs(depth+1, n, k, i+1, t, ans);

        }

    }

    vector<vector<int> > combine(int n, int k) {

        vector<vector<int> > ans;

        vector<int> t(k, 0);

        dfs(0, n, k, 1, t, ans);

        return ans;

    }

};
