class Solution {

public:

    bool legal(string s, int low, int high){

        if(low<0)   return 0;

        if(high-low>3)  return 0;

        if(high-low>1 && s[low]=='0')   return 0;

        if(high-low<3)  return 1;

        int ret = 0;

        for(int i=low; i<high; i++){

            ret *= 10;

            ret += s[i]-'0';

        }

        return ret < 256;

    }

    vector<string> solve(string s, int len, int n){

        vector<string> ans;

        if(len<n)   return ans;

        if(n==1){

            if(legal(s, 0, len))    ans.push_back(s.substr(0, len));

            return ans;

        }

        for(int i=1; i<=3; i++){

            if(legal(s, len-i, len)){

                string ip = s.substr(len-i, i);

                vector<string> t = solve(s, len-i, n-1);

                if(t.size()==0) continue;

                for(auto it=t.begin(); it!=t.end(); it++){

                    *it += '.'+ip;

                    ans.push_back(*it);

                }

            }

        }

        return ans;

    }

    vector<string> restoreIpAddresses(string s) {

        return solve(s, s.length(), 4);

    }

};
