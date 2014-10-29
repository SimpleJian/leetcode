class Solution {

public:

    long long solve(long long a, long long b){

        long long ret = 0;

        while(a>=b){

            long long x = b, k = 1;

            while(x+x < a){

                x = x+x;

                k = k+k;

            }

            a -= x;

            ret += k;

        }

        return ret;

    }

    int divide(int dividend, int divisor) {

        long long a = (long long)dividend;

        long long b = (long long)divisor;

        int s1 = a > 0 ? 1 : -1;

        int s2 = b > 0 ? 1 : -1;

        if(s1<0)    a = -a;

        if(s2<0)    b = -b;

        long long t = solve(a, b);

        return s1==s2 ? t : -t;

    }

};
