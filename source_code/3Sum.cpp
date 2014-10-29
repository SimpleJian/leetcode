class Solution {

public:

    int bs(vector<int> &num, int i, int j, int x){

        while(i+1<j){

            int k = (i+j)>>1;

            if(num[k]>x)    j = k;

            else    i = k;

        }

        if(i<num.size() && num[i]==x)   return i;

        else    return -1;

    }

    vector<vector<int> > threeSum(vector<int> &num) {

        sort(num.begin(), num.end());

        vector<vector<int> > ans;

        vector<int> distinct;

        map<int, int> cnt;

        int n = 0;

        for(int i=0; i<num.size(); i++){

            if(cnt.count(num[i])==0)    cnt[num[i]] = 1;

            else    cnt[num[i]]++;

            if(n<1 || distinct[n-1]!=num[i]){

                distinct.push_back(num[i]);

                n++;

            }

        }

        for(int i=0; i<n; i++){

            for(int j=i+1; j<n; j++){

                int k = bs(distinct, j+1, n, -distinct[i]-distinct[j]);

                if(-1^k){

                    vector<int> t;

                    t.push_back(distinct[i]), t.push_back(distinct[j]), t.push_back(distinct[k]);

                    ans.push_back(t);

                }

            }

        }

        if(cnt.count(0) && cnt[0]>=3)   ans.push_back(vector<int>(3, 0));

        for(int i=0; i<n; i++){

            int x = distinct[i];

            int y = -distinct[i]/2;

            if(x+2*y==0 && x!=y && cnt.count(y) && cnt[y]>=2){

                vector<int> t;

                t.push_back(x), t.push_back(y), t.push_back(y);

                sort(t.begin(), t.end());

                ans.push_back(t);

            }

        }

        return ans;

    }

};
