class Solution {

public:

    string addBinary(string a, string b) {

        int n = a.length();

        int m = b.length();

        int c = 0;

        string ans;

        for(int i=n-1, j=m-1; i>=0 || j>=0; i--, j--){

            int x = i>=0 ? a[i]-'0' : 0;

            int y = j>=0 ? b[j]-'0' : 0;

            ans += ('0'+((x+y+c)&1));

            c = (x+y+c)/2;

        }

        if(c)   ans += '1';

        return string(ans.rbegin(), ans.rend());

    }

};
