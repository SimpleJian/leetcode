class Solution {
public:
    void sortColors(int A[], int n) {
        int n0(0), n1(0);
        for(int i=0; i<n; i++){
            n0 += A[i]==0;
            n1 += A[i]==1;
        }
        for(int i=0; i<n0; i++) A[i] = 0;
        for(int i=n0; i<n0+n1; i++) A[i] = 1;
        for(int i=n0+n1; i<n; i++)  A[i] = 2;
    }
};
