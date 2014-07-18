class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(0==n)    return 0;
        vector<int> f(n, 0);
        vector<int> b(n, 0);
        int ans = 0;
        int low = prices[0], high;
        for(int i=0; i<prices.size(); i++){
            high = prices[i];
            ans = max(ans, high-low);
            f[i] = ans;
            low = min(low, high);
        }
        ans = 0;
        high = prices[n-1];
        for(int i=n-1; i>=0; i--){
            low = prices[i];
            ans = max(ans, high-low);
            b[i] = ans;
            high = max(high, low);
        }
        ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, f[i]+b[i]);
        }
        return ans;
    }
};
