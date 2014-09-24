class Solution {

public:

    void merge(int A[], int m, int B[], int n) {

        for(int i=n+m-1; i>=n; i--){

            A[i] = A[i-n];

        }

        int i=n, j=0, k=0;

        while(i<n+m || j<n){

            if(i<n+m && j<n){

                if(A[i]<B[j])   A[k++] = A[i++];

                else    A[k++] = B[j++];

            }

            else if(i<n+m)  A[k++] = A[i++];

            else    A[k++] = B[j++];

        }

    }

};
