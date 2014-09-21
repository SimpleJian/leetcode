class Solution {

public:

    int climbStairs(int n) {

        vector<int> f(50, 1);

        for(int i=2; i<50; i++){

            f[i] = f[i-1]+f[i-2];

        }

        return f[n];

    }

};
