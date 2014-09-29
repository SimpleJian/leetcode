class Solution {

public:

    void dfs(int depth, int low, int target, vector<int> t, vector<int> &candidates, vector<vector<int> > &ans){

        if(target<=0){

            if(0==target)   ans.push_back(t);

            return;

        }

        if(t.size()<depth+1)    t.push_back(0);

        for(int i=low; i<candidates.size(); i++){

            t[depth] = candidates[i];

            dfs(depth+1, i, target-candidates[i], t, candidates, ans);

        }

    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int> > ans;

        dfs(0, 0, target, vector<int>(), candidates, ans);

        return ans;

    }

};
