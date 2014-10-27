class Solution {

public:

    int candy(vector<int> &ratings) {

        int n = ratings.size();

        if(n<1) return 0;

        vector<int> f(n, 0);

        for(int i=0; i<n; i++){

            if((i-1<0 || ratings[i]<=ratings[i-1]) && (i+1>=n || ratings[i]<=ratings[i+1]))  f[i] = 1;

        }

        for(int i=0; i<n; i++){

            if(f[i]^1)  continue;

            for(int j=i-1; j>=0 && ratings[j]>ratings[j+1]; j--){

                f[j] = max(f[j], f[j+1] + 1);

            }

            for(int j=i+1; j<n && ratings[j]>ratings[j-1]; j++){

                f[j] = max(f[j], f[j-1] + 1);

            }

        }

        int ans = 0;

        for(int i=0; i<n; i++)  ans += f[i];

        return ans;

    }

};
