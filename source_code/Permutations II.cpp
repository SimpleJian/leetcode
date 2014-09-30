class Solution {

public:

    void dfs(int depth, int n, vector<int> &t, unordered_map<int, int> cnt, vector<vector<int> > &ans){

        if(depth==n){

            ans.push_back(t);

            return;

        }

        for(auto it=cnt.begin(); it!=cnt.end(); it++){

            int key = it->first;

            if(cnt[key]>0){

                cnt[key]--;

                t[depth] = key;

                dfs(depth+1, n, t, cnt, ans);

                cnt[key]++;

            }

        }

    }

    vector<vector<int> > permuteUnique(vector<int> &num) {

        int n = num.size();

        unordered_map<int, int> cnt;

        vector<int> t(n, 0);

        vector<vector<int> > ans;

        for(int i=0; i<n; i++){

            if(cnt.count(num[i])==0)    cnt[num[i]] = 1;

            else    cnt[num[i]]++;

        }

        dfs(0, n, t, cnt, ans);

        return ans;

    }

};
