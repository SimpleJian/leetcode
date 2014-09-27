class Solution {

public:

    int dp(int i, int j, vector<vector<int> > &grid, vector<vector<int> > &f){

        if(f[i][j]>=0)  return f[i][j];

        if(i==0 && j==0)    return f[i][j] = grid[i][j];

        if(i>0 && j>0)  return f[i][j] = grid[i][j]+min(dp(i-1, j, grid, f), dp(i, j-1, grid, f));

        if(i>0) return f[i][j] = grid[i][j]+dp(i-1, j, grid, f);

        return f[i][j] = grid[i][j]+dp(i, j-1, grid, f);

    }

    int minPathSum(vector<vector<int> > &grid) {

        int n = grid.size();

        if(n<1) return 0;

        int m = grid[0].size();

        if(m<1) return 0;

        vector<vector<int> > f(n, vector<int>(m, -1));

        return dp(n-1, m-1, grid, f);

    }

};
