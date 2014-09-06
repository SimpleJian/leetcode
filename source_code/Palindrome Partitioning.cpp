class Solution {
public:
    bool palindrome(string s, int i, int j){
        while(i<j){
            if(s[i]^s[j])   return false;
            i++, j--;
        }
        return true;
    }
    void dfs(vector<vector<string> > &ans, vector<string> &t, string s, int k){
        if(k>=s.length()){
            ans.push_back(t);
            return;
        }
        for(int i=k; i<s.length(); i++){
            if(palindrome(s, k, i)){
                t.push_back(s.substr(k, i-k+1));
                dfs(ans, t, s, i+1);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> t;
        dfs(ans, t, s, 0);
        return ans;
    }
};
