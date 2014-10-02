class Solution {

public:

    void dfs(int depth, int target, int low, vector<int> num, vector<int> t, vector<vector<int> > &ans){

        if(target<=0){

            if(0==target)   ans.push_back(t);

            return;

        }

        if(t.size()<depth+1)    t.push_back(0);

        for(int i=low; i<num.size(); i++){

            t[depth] = num[i];

            if(num[i]<=target)  dfs(depth+1, target-num[i], i+1, num, t, ans);

            else    return;

            while(i+1<num.size() && num[i]==num[i+1])   i++;

        }

    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {

        sort(num.begin(), num.end());

        vector<vector<int> > ans;

        vector<int> t;

        dfs(0, target, 0, num, t, ans);

        return ans;

    }

};
