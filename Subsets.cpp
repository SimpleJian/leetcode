class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int n = S.size();
        vector<vector<int> > ans;
        for(int i=0; i<(1<<n); i++){
            vector<int> t;
            for(int j=0; j<n; j++){
                if(i & (1<<j))  t.push_back(S[j]);
            }
            sort(t.begin(), t.end());
            ans.push_back(t);
        }
        return ans;
    }
};
