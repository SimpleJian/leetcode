class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int i=-1, j=-1;
        int low = -1, high = n-1, mid;
        while(low+1<high){
            mid = (low+high+1)>>1;
            if(A[mid]<target)   low = mid;
            else    high = mid;
        }
        if(A[high]==target) i = high;
        low = 0, high = n;
        while(low+1<high){
            mid = (low+high)>>1;
            if(A[mid]>target)   high = mid;
            else    low = mid;
        }
        if(A[low]==target)  j = low;
        vector<int> ans;
        ans.push_back(i);
        ans.push_back(j);
        return ans;
    }
};
