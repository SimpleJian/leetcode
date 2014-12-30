class Solution {

public:

    int trailingZeroes(int n) {

        int e2 = 0, e5 = 0;

        int t = n;

        while(t){

            e2 += (t>>1);

            t >>= 1;

        }

        while(n){

            e5 += n/5;

            n /= 5;

        }

        return min(e2, e5);

    }

};
