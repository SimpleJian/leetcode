class Solution {

public:

    void init(map<int, string> &f){

        f[2] = "abc";   f[3] = "def";

        f[4] = "ghi";   f[5] = "jkl";

        f[6] = "mno";   f[7] = "pqrs";

        f[8] = "tuv";   f[9] = "wxyz";

    }

    void dfs(int depth, string digits, string t, vector<string> &ans, map<int, string> &f){

        if(depth==digits.length()){

            ans.push_back(t);

        }

        string s = f[digits[depth]-'0'];

        for(int i=0; i<s.length(); i++){

            t[depth] = s[i];

            dfs(depth+1, digits, t, ans, f);

        }

    }

    vector<string> letterCombinations(string digits) {

        string t = digits;

        vector<string> ans;

        map<int, string> f;

        init(f);

        dfs(0, digits, t, ans, f);

        return ans;

    }

};
