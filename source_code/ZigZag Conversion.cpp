class Solution {

public:

    string convert(string s, int nRows) {

        int n = s.length();

        if(nRows<2) return s;

        int nCols = n / 2 + 1;  // (nRows+nRows-2) / (nRows-1) = 2

        vector<string> m(nRows, string(nCols, 0));

        int d = 0;

        int di[] = {1, -1};

        int dj[] = {0, 1};

        int i=0, j=0, k=0;

        while(k<n){

            m[i][j] = s[k++];

            int ni = i+di[d];

            if(ni<0 || ni>=nRows)   d ^= 1;

            i += di[d];

            j += dj[d];

        }

        string ans;

        for(int i=0; i<nRows; i++){

            for(int j=0; j<nCols; j++){

                if(m[i][j]) ans += m[i][j];

            }

        }

        return ans;

    }

};
