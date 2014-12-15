class Solution {

public:

    vector<int> findSubstring(string S, vector<string> &L) {

        if(0==L.size() || 0==L[0].length()) return vector<int>();

        vector<int> ans;

        int n = L.size();

        int len = L[0].length();

        unordered_map<string, int> m;

        unordered_map<string, int>::iterator it;

        for(int i=0; i<n; i++)  m[L[i]]++;

        for(int i=0; i+n*len-1 < S.length(); i++){

            unordered_map<string, int> strmap = m;

            bool yes = 1;

            for(int k=0; k<n; k++){

                if((it = strmap.find(S.substr(i+k*len,len)))!=strmap.end()&&it->second>0)  it->second--;

                else{

                    yes = 0;

                    break;

                }

            }

            if(yes) ans.push_back(i);

        }

        return ans;

    }

};
