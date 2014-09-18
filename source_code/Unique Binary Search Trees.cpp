class Solution {

public:

    int numTrees(int n) {

        if(0==n)    return 1;

        int ans = 0;

        for(int i=1; i<=n; i++){

            ans += numTrees(i-1) * numTrees(n-i);

        }

        return ans;

    }

};
