class Solution {

public:

    double pow(double x, int n) {

        int sign = n >= 0 ? 1 : -1;

        double ans = 1.0;

        long long m = (long long)n * sign;

        while(m){

            if(m&1) ans *= x;

            x *= x;

            m /= 2;

        }

        return sign>0 ? ans : 1.0 / ans;

    }

};
