class Solution {

public:

    int maxProfit(vector<int> &prices) {

        int n = prices.size();

        if(n<=1) return 0;

        int ans = 0;

        int pre_min = prices[0];

        for(int i=1; i<n; i++){

            ans = max(ans, prices[i]-pre_min);

            pre_min = min(pre_min, prices[i]);

        }

        return ans;

    }

};
