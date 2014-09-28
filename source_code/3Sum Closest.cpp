class Solution {

public:

    pair<int,int> bs(vector<int> &num, int x, int low, int high){

        int n = high-low+1;

        if(n<1) return make_pair(0x3f3f3f3f,0x3f3f3f3f);

        if(n<2) return make_pair(num[low], abs(num[low]-x));

        int mid;

        while(low+1<high){

            if(num[low]>=x || num[high]<=x) break;

            mid = (low+high)>>1;

            if(num[mid]>=x) high = mid;

            else    low = mid;

        }

        int d1 = abs(num[low]-x);

        int d2 = abs(num[high]-x);

        if(d1<d2)   return make_pair(num[low], d1);

        else    return make_pair(num[high], d2);

    }

    int threeSumClosest(vector<int> &num, int target) {

        int n = num.size();

        int d = 0x3f3f3f3f, sum;

        sort(num.begin(), num.end());

        for(int i=0; i<n; i++){

            for(int j=i+1; j<n; j++){

                int sum2 = num[i]+num[j];

                pair<int,int> t = bs(num, target-sum2, j+1, n-1);

                if(t.second<d){

                    d = t.second;

                    sum = sum2+t.first;

                }

            }

        }

        return sum;

    }

};
