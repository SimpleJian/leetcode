class Solution {
public:
    int search(int A[], int n, int target) {
        int i=0;
        for(int j=0; j<n; j++){
            if(j-1>=0 && A[j]<A[j-1]){
                i = j;
                break;
            }
        }
        int low, high, mid;
        low = 0, high = i;
        while(low+1<high){
            mid = (low+high)>>1;
            if(A[mid]>target)   high = mid;
            else    low = mid;
        }
        if(A[low]==target)  return low;
        low = i, high = n;
        while(low+1<high){
            mid = (low+high)>>1;
            if(A[mid]>target)   high = mid;
            else    low = mid;
        }
        if(A[low]==target)  return low;
        return -1;
    }
};
