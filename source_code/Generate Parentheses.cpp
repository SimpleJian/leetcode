class Solution {

public:

    vector<string> dp(int n, vector<int> &f, vector<vector<string> > &ans){

        if(f[n])    return ans[n];

        f[n] = 1;

        vector<string> ret;

        if(0==n){

            ret.push_back("");

            return ans[n] = ret;

        }

        for(int i=0; i<n; i++){

            dp(i, f, ans);

            dp(n-1-i, f, ans);

            for(int j=0; j<ans[i].size(); j++){

                for(int k=0; k<ans[n-1-i].size(); k++){

                    ret.push_back(ans[i][j]+'('+ans[n-1-i][k]+')');

                }

            }

        }

        return ans[n] = ret;

    }

    vector<string> generateParenthesis(int n) {

        vector<int> f(n+1, 0);

        vector<vector<string> > ans(n+1, vector<string>());

        return dp(n, f, ans);

    }

};
