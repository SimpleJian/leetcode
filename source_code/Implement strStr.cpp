class Solution {

public:

    char *strStr(char *haystack, char *needle) {

        int n = strlen(haystack);

        int m = strlen(needle);

        vector<int> next(m, -1);

        int k = -1;

        for(int i=1; i<m; i++){

            while(k>=0 && needle[k+1]!=needle[i])   k = next[k];

            if(needle[k+1]==needle[i])  k++;

            next[i] = k;

        }

        k = -1;

        if(k==m-1)  return haystack;

        for(int i=0; i<n; i++){

            while(k>=0 && needle[k+1]!=haystack[i]) k = next[k];

            if(needle[k+1]==haystack[i])    k++;

            if(k==m-1)  return haystack+i-k;

        }

        return NULL;

    }

};
