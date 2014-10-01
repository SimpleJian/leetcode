class Solution {

public:

    string next(string s){

        string ret;

        if(s.length()<1)    return ret;

        int last = s[0]-'0', cnt = 1;

        for(int i=1; i<s.length(); i++){

            int t = s[i]-'0';

            if(t==last) cnt++;

            else{

                ret += cnt+'0';

                ret += last+'0';

                last = t;

                cnt = 1;

            }

        }

        ret += cnt+'0';

        ret += last+'0';

        return ret;

    }

    string countAndSay(int n) {

        if(n<1) return "";

        string ans = "1";

        for(int i=0; i<n-1; i++)    ans = next(ans);

        return ans;

    }

};
