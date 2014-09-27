class Solution {

public:

    int dp(int i, int j, vector<vector<int> > &map, vector<vector<int> > &f){

        if(f[i][j]>-1)  return f[i][j];

        if(map[i][j])   return f[i][j] = 0;

        if(i==0 && j==0)    return f[i][j] = 1;

        if(i>0 && j>0)  return f[i][j] = dp(i-1, j, map, f)+dp(i, j-1, map, f);

        if(i>0) return f[i][j] = dp(i-1, j, map, f);

        else    return f[i][j] = dp(i, j-1, map, f);

    }

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {

        int n = obstacleGrid.size();

        if(n<1) return 0;

        int m = obstacleGrid[0].size();

        if(m<1) return 0;

        vector<vector<int> > f(n, vector<int>(m, -1));

        return dp(n-1, m-1, obstacleGrid, f);

    }

};
