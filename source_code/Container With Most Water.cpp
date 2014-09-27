class Solution {

public:

    int maxArea(vector<int> &height) {

        int n = height.size();

        if(n<=1)    return 0;

        

        vector<pair<int, int> > a;

        for(int i=0; i<n; i++)  a.push_back(make_pair(height[i], i));

        sort(a.begin(), a.end());



        int ans = 0;

        int low = a[n-1].second;

        int high = a[n-1].second;

        for(int i=n-2; i>=0; i--){

            ans = max(ans, a[i].first*(max(abs(a[i].second-low), abs(a[i].second-high))));

            low = min(low, a[i].second);

            high = max(high, a[i].second);

        }

        return ans;

    }

};
