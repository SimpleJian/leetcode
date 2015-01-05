class Solution {

public:

    string lastLine(vector<string> t, int n, int len, int L){

        string ans = t[0];

        for(int i=1; i<n; i++)  ans += ' '+t[i];

        return ans+string(L-len-n+1, ' ');

    }

    string align(vector<string> t, int n, int len, int L){

        if(1==n)    return t[0]+string(L-len, ' ');

        int spaces = L-len;

        int avg = spaces / (n-1);

        int left = spaces % (n-1);

        string ans = t[0];

        for(int i=1; i<n; i++){

            ans += string(i<=left?avg+1:avg, ' ');

            ans += t[i];

        }

        return ans;

    }

    vector<string> fullJustify(vector<string> &words, int L) {

        vector<string> t;

        vector<string> ans;

        int n=0, len=0;

        int done = 0;

        for(int i=0; i<words.size(); i++){

            if(words[i].length()+len+n>L){

                done += n;

                if(done<words.size())    ans.push_back(align(t, n, len, L));

                else    ans.push_back(lastLine(t, n, len, L));

                t.clear();

                n = len = 0;

            }

            len += words[i].length();

            n++;

            t.push_back(words[i]);

        }

        if(t.size())    ans.push_back(lastLine(t, n, len, L));

        return ans;

    }

};
