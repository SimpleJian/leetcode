class Solution {
public:
    bool canJump(int A[], int n) {
        vector<int> f(n, 0);
        vector<int> s(n+1, 0);
        f[n-1] = 1;
        s[n] = 0;
        s[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            int start = i+1;
            int end = min(i+A[i], n-1);
            if(end>=start){
                f[i] = (s[start]-s[end+1])>0;
            }
            s[i] = s[i+1] + f[i];
        }
        return f[0];
    }
};
