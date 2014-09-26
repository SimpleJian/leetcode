class Solution {

public:

    void setRow(vector<vector<int> > &matrix, int row, int n, int m){

        for(int j=0; j<m; j++)  matrix[row][j] = 0;

    }

    void setCol(vector<vector<int> > &matrix, int col, int n, int m){

        for(int i=0; i<n; i++)  matrix[i][col] = 0;

    }

    void setZeroes(vector<vector<int> > &matrix) {

        int n = matrix.size();

        if(n<1) return;

        int m = matrix[0].size();

        if(m<1) return;

        int r0 = 0, l0 = 0;

        for(int j=0; j<m; j++)  if(matrix[0][j]==0) r0 = 1;

        for(int i=0; i<n; i++)  if(matrix[i][0]==0) l0 = 1;

        for(int i=1; i<n; i++){

            for(int j=1; j<m; j++){

                if(matrix[i][j]==0) matrix[i][0] = matrix[0][j] = 0;

            }

        }

        for(int i=1; i<n; i++)  if(matrix[i][0]==0) setRow(matrix, i, n, m);

        for(int j=1; j<m; j++)  if(matrix[0][j]==0) setCol(matrix, j, n, m);

        if(r0)  setRow(matrix, 0, n, m);

        if(l0)  setCol(matrix, 0, n, m);

    }

};
