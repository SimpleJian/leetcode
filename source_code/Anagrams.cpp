class Solution {

public:

    vector<string> anagrams(vector<string> &strs) {

        vector<string> s(strs);

        vector<string> ans;

        map<string, int> strm;

        for(int i=0; i<s.size(); i++){

            sort(s[i].begin(), s[i].end());

            if(strm.count(s[i])==0) strm[s[i]] = 1;

            else    strm[s[i]]++;

        }

        for(int i=0; i<s.size(); i++){

            if(strm[s[i]]>1)    ans.push_back(strs[i]);

        }

        return ans;

    }

};
