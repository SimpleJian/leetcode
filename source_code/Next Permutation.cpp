class Solution {

public:

    void nextPermutation(vector<int> &num) {

        int n = num.size();

        if(n<2) return;

        int i, j;

        for(i=n-2; i>=0; i--){

            if(num[i]<num[i+1]) break;

        }

        if(i<0){

            reverse(num.begin(), num.end());

            return;

        }

        int min_bigger = num[i+1];

        int id = i+1;

        for(j=i+1; j<n; j++){

            if(num[j]>num[i] && num[j]<=min_bigger){

                min_bigger = num[j];

                id = j;

            }

        }

        swap(num[i], num[id]);

        reverse(num.begin()+i+1, num.end());

    }

};
