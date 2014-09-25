class Solution {

public:

    void rotate(vector<vector<int> > &matrix) {

        int n = matrix.size();

        for(int i=0; i<=(n-1)/2; i++){

            for(int j=0; j<n/2; j++){

                int x=i, y=j, t, pre=matrix[i][j];

                for(int k=0; k<4; k++){

                    t = x;

                    x = y;

                    y = n-1-t;

                    swap(pre, matrix[x][y]);

                }

            }

        }

    }

};
