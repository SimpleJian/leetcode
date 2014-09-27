class Solution {

public:

    bool searchMatrix(vector<vector<int> > &matrix, int target) {

        int n = matrix.size();

        if(n<1) return 0;

        int m = matrix[0].size();

        if(m<1) return 0;

        int low = 0, high = n, mid;

        while(low+1<high){

            mid = (low+high)>>1;

            if(target < matrix[mid][0]) high = mid;

            else    low = mid;

        }

        if(target < matrix[low][0] || target > matrix[low][m-1])   return 0;

        int row = low;

        low = 0, high = m;

        while(low+1<high){

            mid = (low+high)>>1;

            if(target < matrix[row][mid])   high = mid;

            else    low = mid;

        }

        return target==matrix[row][low];

    }

};
