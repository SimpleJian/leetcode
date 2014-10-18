class Solution {

public:

    string getPermutation(int n, int k) {

        vector<int> f(10, 0), fac(10, 1);

        for(int i=2; i<10; i++) fac[i] = fac[i-1] * i;

        string ans;

        k--;

        while(n){

            int t = k / fac[n-1];

            int cnt = 0;

            for(int i=1; i<10; i++){

                if(f[i])    continue;

                if(t==cnt++){

                    f[i] = 1;

                    ans += i+'0';

                    k -= t*fac[n-1];

                    n--;

                    break;

                }

            }

        }

        return ans;

    }

};
