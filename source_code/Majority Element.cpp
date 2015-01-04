class Solution {

public:

    int majorityElement(vector<int> &num) {

        int t, c = 0;

        for(int i=0; i<num.size(); i++){

            if(0==c)    t = num[i], c = 1;

            else    c += t==num[i] ? 1 : -1;

        }

        return t;

    }

};
