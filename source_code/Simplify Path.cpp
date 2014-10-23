class Solution {

public:

    void fill(vector<string> &s, int &k, string t){

        if(t.length()==0)   return;

        if(s.size()<k+1)  s.push_back(t);

        else    s[k] = t;

        k++;

    }

    string simplifyPath(string path) {

        path += '/';

        vector<string> vs;

        string t;

        int k = 0;

        for(int i=0; i<path.length(); i++){

            if(path[i]=='/'){

                if(t.length()<1)    continue;

                if(t.compare("..")==0){

                    if(k)   k--;

                }

                else if(t.compare(".")) fill(vs, k, t);

                t = "";

            }

            else    t += path[i];

        }

        string ans;

        for(int i=0; i<k; i++){

            ans += '/';

            ans += vs[i];

        }

        if(ans=="") ans += '/';

        return ans;

    }

};
