class Solution {

public:

    long long gcd(long long a, long long b){

        return b ? gcd(b, a%b) : a;

    }

    string fractionToDecimal(int numerator, int denominator) {

        long long t = gcd(numerator, denominator);

        long long a = numerator / t;

        long long b = denominator / t;

        int sa = a>=0 ? 1 : -1;

        int sb = b>=0 ? 1 : -1;

        a *= sa;

        b *= sb;

        string ans;

        t = a/b;

        if(0==t)    ans += '0';

        while(t){

            char c = '0'+t%10;

            ans =  c + ans;

            t /= 10;

        }

        a %= b;

        if(a){

            ans += '.';

            unordered_map<long long, int> r;

            int p = ans.length();

            r[a] = p++;

            while(a){

                a *= 10;

                ans += '0'+a/b;

                a %= b;

                if(r.count(a)){

                    ans.insert(r[a], 1, '(');

                    ans += ')';

                    break;

                }

                r[a] = p++;

            }

        }

        if(sa^sb)   ans = '-'+ans;

        return ans;

    }

};
