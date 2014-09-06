class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > f(numRows, vector<int>());
        for(int i=0; i<numRows; i++){
            f[i] = vector<int>(i+1);
        }
        if(0==numRows)  return f;
        f[0][0] = 1;
        for(int i=1; i<numRows; i++){
            f[i][0] = f[i][i] = 1;
            for(int j=1; j<i; j++)  f[i][j] = f[i-1][j-1]+f[i-1][j];
        }
        return f;
    }
};
