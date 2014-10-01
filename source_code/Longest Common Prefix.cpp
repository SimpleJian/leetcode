class Solution {

public:

    string LCP(string s1, string s2){

        string ret;

        for(int i=0; i<s1.length() && i<s2.length(); i++){

            if(s1[i]==s2[i])    ret += s1[i];

            else    break;

        }

        return ret;

    }

    string longestCommonPrefix(vector<string> &strs) {

        string ans;

        int n = strs.size();

        if(n<1) return ans;

        ans = strs[0];

        for(int i=1; i<n; i++)  ans = LCP(ans, strs[i]);

        return ans;

    }

};
