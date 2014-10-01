class Solution {

public:

    int trap(int A[], int n) {

        if(n<=2)    return 0;

        int max_h = 0, max_i = 0;

        for(int i=0; i<n; i++){

            if(A[i]>=max_h){

                max_h = A[i];

                max_i = i;

            }

        }

        int ans = 0;

        int last = A[0];

        for(int i=1; i<=max_i; i++){

            if(A[i]>=last)  last = A[i];

            else    ans += last-A[i];

        }

        last = A[n-1];

        for(int i=n-2; i>=max_i; i--){

            if(A[i]>=last)  last = A[i];

            else    ans += last-A[i];

        }

        return ans;

    }

};
