class Solution {

public:

    int maxProfit(vector<int> &prices) {

        vector<int> p;

        int n = 0;

        for(int i=0; i<prices.size(); i++){

            if(n&1){

                if((i-1<0 || prices[i-1]<=prices[i]) && (i+1>=prices.size() || prices[i+1]<=prices[i])){

                    p.push_back(prices[i]);

                    n++;

                }

            }

            else{

                if((i-1<0 || prices[i-1]>=prices[i]) && (i+1>=prices.size() || prices[i+1]>=prices[i])){

                    p.push_back(prices[i]);

                    n++;

                }

            }

        }

        int ans = 0;

        for(int i=0; i+1<n; i+=2){

            ans += p[i+1]-p[i];

        }

        return ans;

    }

};
