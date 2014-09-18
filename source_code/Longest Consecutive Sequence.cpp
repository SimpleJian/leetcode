// good problem of disjoint-set

class Solution {

public:

    int get_father(int x, unordered_map<int, int> &f){

        if(x==f[x]) return x;

        return f[x] = get_father(f[x], f);

    }

    int longestConsecutive(vector<int> &num) {

        unordered_map<int, int> len;

        unordered_map<int, int> f;

        int ans = 0;

        for(int i=0; i<num.size(); i++){

            int x = num[i];

            if(f.count(x))  continue;

            if(f.count(x-1) && f.count(x+1)){

                int f1 = get_father(x-1, f);

                f[x] = f1;

                f[x+1] = f1;

                len[f1] += 1+len[x+1];

                ans = max(ans, len[f1]);

            }

            else if(f.count(x-1) && !f.count(x+1)){

                int f1 = get_father(x-1, f);

                f[x] = f1;

                len[f1] += 1;

                ans = max(ans, len[f1]);

            }

            else if(!f.count(x-1) && f.count(x+1)){

                f[x] = x;

                f[x+1] = x;

                len[x] = len[x+1]+1;

                ans = max(ans, len[x]);

            }

            else{

                f[x] = x;

                len[x] = 1;

                ans = max(ans, 1);

            }

        }

        return ans;

    }

};
