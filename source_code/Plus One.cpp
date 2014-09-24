class Solution {

public:

    vector<int> plusOne(vector<int> &digits) {

        int n = digits.size();

        digits[n-1]++;

        for(int i=n-1; i>0; i--){

            if(digits[i]>=10){

                digits[i] -= 10;

                digits[i-1] += 1;

            }

            else    break;

        }

        if(digits[0]>=10){

            digits[0] -= 10;

            vector<int> ans;

            ans.push_back(1);

            for(int i=0; i<n; i++)  ans.push_back(digits[i]);

            return ans;

        }

        else    return digits;

    }

};
