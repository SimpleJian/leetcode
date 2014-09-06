class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i=0; i<n; i++){
            if(A[i]<1 || A[i]>n)    A[i] = 0;
        }
        for(int i=0; i<n; i++){
            int j = A[i]-1;
            while(j>=0){
                int x = A[j];
                A[j] = -1;
                j = x-1;
            }
        }
        for(int i=0; i<n; i++){
            if(-1 != A[i])  return i+1;
        }
        return n+1;
    }
};
