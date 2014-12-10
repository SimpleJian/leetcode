class Solution {

public:

    bool match(char a, char b){

        return a==b || a=='.' || b=='.';

    }

    bool dfs(const char *s, const char *p, int i, int j){

        if(j==strlen(p))    return i==strlen(s);

        if(j+1<strlen(p) && p[j+1]=='*'){

            int t;

            for(t=j+2; t<strlen(p) && p[t]=='*'; t++);

            for(int k=i; k<strlen(s) && match(s[k], p[j]); k++){

                if(dfs(s, p, k+1, t))   return 1;

            }

            if(dfs(s, p, i, t)) return 1;

        }

        else    return match(s[i], p[j]) ? dfs(s, p, i+1, j+1) : 0;

    }

    bool isMatch(const char *s, const char *p) {

        return dfs(s, p, 0, 0);

    }

};
