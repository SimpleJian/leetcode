class Solution {

public:

    int lengthOfLongestSubstring(string s) {

        int ans = 0;

        for(int i=0; i<s.length(); i++){

            vector<int> pos(128, -1);

            int j;

            for(j=i; j<s.length(); j++){

                if(-1==pos[s[j]])   pos[s[j]] = j;

                else    break;

            }

            ans = max(ans, j-i);

            if(j==s.length())   break;

            else    i = pos[s[j]];

        }

        return ans;

    }

};
