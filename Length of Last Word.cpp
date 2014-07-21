class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int ans = 0;
        for(int i=0; s[i]; i++){
            if(' ' != s[i]){
                if(i-1<0 || ' '==s[i-1])    ans = 1;
                else    ans++;
            }
        }
        return ans;
    }
};
