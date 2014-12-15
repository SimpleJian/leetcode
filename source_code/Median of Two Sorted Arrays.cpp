class Solution {

public:

    int get_kth(int A[], int m, int B[], int n, int k){

        if(0==m)    return B[k-1];

        if(0==n)    return A[k-1];

        if(1==k)    return min(A[0], B[0]);

        int i = min(m, k/2), j = min(n, k/2);

        if(A[i-1]<B[j-1])   return get_kth(A+i, m-i, B, n, k-i);

        else    return get_kth(A, m, B+j, n-j, k-j);

    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {

        int l = (m+n+1)>>1;

        int r = (m+n+2)>>1;

        return (get_kth(A, m, B, n, l) + get_kth(A, m, B, n, r)) / 2.0;

    }

};
