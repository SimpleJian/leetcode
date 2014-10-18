<F9>class Solution {

public:

    string longestPalindrome(string s) {

        string t;

        for(int i=0; i<s.length(); i++){

            t += '#';

            t += s[i];

        }

        t += '#';

        int n = t.length();

        vector<int> p(n, 0);

        int id = 0, mx = 0;

        for(int i=0; i<n; i++){

            p[i] = mx>i ? min(p[2*id-i], mx-i) : 1;

            while(i-p[i]>=0 && i+p[i]<n && t[i-p[i]]==t[i+p[i]])    p[i]++;

            if(i+p[i]>mx){

                mx = i+p[i];

                id = i;

            }

        }

        int mid = 0, len = 0;

        for(int i=0; i<n; i++){

            if(p[i]-1 > len){

                len = p[i]-1;

                mid = i;

            }

        }

        string ans;

        for(int i=mid-p[mid]+1; i<mid+p[mid]; i++)  if(t[i]!='#')   ans += t[i];

        return ans;

    }

};
