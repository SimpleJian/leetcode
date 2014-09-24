class Solution {

public:

    int uniquePaths(int m, int n) {

        int N = 201;

        vector<vector<int> > C(N, vector<int>(N, 0));

        C[0][0] = 1;

        for(int i=1; i<N; i++){

            C[i][0] = C[i][i] = 1;

            for(int j=1; j<i; j++){

                C[i][j] = C[i-1][j-1] + C[i-1][j];

            }

        }

        return C[n+m-2][n-1];

    }

};
