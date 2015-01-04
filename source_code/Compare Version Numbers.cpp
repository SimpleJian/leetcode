class Solution {

public:

    vector<int> convert(string version){

        vector<int> ans;

        int t = 0;

        for(int i=0; ; i++){

            if(version[i]=='.' || i==version.length()){

                ans.push_back(t);

                t = 0;

                if(i==version.length()) break;

            }

            else    t = t*10 + version[i]-'0';

        }

        return ans;

    }

    int compareVersion(string version1, string version2) {

        vector<int> v1 = convert(version1);

        vector<int> v2 = convert(version2);

        for(int i=0; i<v1.size() || i<v2.size(); i++){

            int a = i<v1.size() ? v1[i] : 0;

            int b = i<v2.size() ? v2[i] : 0;

            if(a>b) return 1;

            if(a<b) return -1;

        }

        return 0;

    }

};
