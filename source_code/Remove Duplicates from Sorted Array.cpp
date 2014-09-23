class Solution {

public:

    int removeDuplicates(int A[], int n) {

        if(n<=0)    return 0;

        int cnt = 0;

        int last = A[0];

        A[cnt++] = A[0];

        for(int i=1; i<n; i++){

            if(A[i]!=last){

                A[cnt++] = A[i];

                last = A[i];

            }

        }

        return cnt;

    }

};
