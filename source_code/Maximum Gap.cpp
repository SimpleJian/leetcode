class Solution {

public:

    void radixSort(vector<int> &num){

        for(int i=0; i<31; i++){

            int k = (1<<i);

            vector<int> oneBucket, zeroBucket;

            for(int j=0; j<num.size(); j++){

                if(num[j] & k)  oneBucket.push_back(num[j]);

                else    zeroBucket.push_back(num[j]);

            }

            int j=0;

            for(j=0; j<zeroBucket.size(); j++)  num[j] = zeroBucket[j];

            for(; j<num.size(); j++)    num[j] = oneBucket[j-zeroBucket.size()];

        }

    }

    int maximumGap(vector<int> &num) {

        if(num.size()<2)    return 0;

        radixSort(num);

        int ans = num[1]-num[0];

        for(int i=1; i+1<num.size(); i++)   ans = max(ans, num[i+1]-num[i]);

        return ans;

    }

};
