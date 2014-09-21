class Solution {

public:

    int maxSubArray(int A[], int n) {

        vector<int> s(n+1, 0);

        s[0] = 0;

        for(int i=1; i<=n; i++) s[i] = s[i-1]+A[i-1];

        int min_pre = s[0];

        int ans = A[0];

        for(int i=1; i<=n; i++){

            ans = max(ans, s[i]-min_pre);

            min_pre = min(min_pre, s[i]);

        }

        return ans;

    }

};
