class Solution {

public:

    void check(int A[], int i, int j, int &ans){

        int t = 1;

        for(int k=i; k<j; k++){

            t *= A[k];

            ans = max(ans, t);

        }

        t = 1;

        for(int k=j-1; k>=i; k--){

            t *= A[k];

            ans = max(ans, t);

        }

    }

    int maxProduct(int A[], int n) {

        if(n<2) return A[0];

        int ans = 0;

        int t = 1;

        for(int i=0, j=0; i<n;){

            if(0==A[j] || j==n){

                check(A, i, j, ans);

                i = ++j;

            }

            else    j++;

        }

        return ans;

    }

};
