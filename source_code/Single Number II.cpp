class Solution {

public:

    long long xor3(long long x, long long y){

        long long base = 1;

        long long ret = 0;

        while(x || y){

            ret += ((x%3+y%3)%3) * base;

            x /= 3;

            y /= 3;

            base *= 3;

        }

        return ret;

    }

    int singleNumber(int A[], int n) {

        long long x = 0;

        for(int i=0; i<n; i++){

            long long y = abs((long long)A[i]) * 3 + (A[i]<0 ? 1 : 0);

            x = xor3(x, y);

        }

        if(x%3) return  -x/3;

        else    return x/3;

    }

};
