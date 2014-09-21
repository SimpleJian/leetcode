class Solution {

public:

    int searchInsert(int A[], int n, int target) {

        int low = -1, high = n;

        while(low+1<high){

            int mid = (low+high)>>1;

            if(A[mid]<target)   low = mid;

            else    high = mid;

        }

        return low+1;

    }

};
