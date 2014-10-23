class Solution {

public:

    bool dfs(vector<vector<char> > &b, vector<vector<int> > &v, string &s, int k, int i, int j, int n, int m){

        int dx[4] = {0, 1, 0, -1};

        int dy[4] = {-1, 0, 1, 0};

        if(k>=s.length())   return 1;

        for(int t=0; t<4; t++){

            int ni = i+dx[t];

            int nj = j+dy[t];

            if(ni<0 || nj<0 || ni>=n || nj>=m)  continue;

            if(v[ni][nj] || b[ni][nj]!=s[k])    continue;

            v[ni][nj] = 1;

            if(dfs(b, v, s, k+1, ni, nj, n, m)) return 1;

            v[ni][nj] = 0;

        }

        return 0;

    }

    bool exist(vector<vector<char> > &board, string word) {

        int n = board.size();

        if(n<1) return 0;

        int m = board[0].size();

        if(m<1) return 0;

        if(word.length()<1) return 1;

        vector<vector<int> > vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                if(board[i][j]==word[0]){

                    vis[i][j] = 1;

                    if(dfs(board, vis, word, 1, i, j, n, m))   return 1;

                    vis[i][j] = 0;

                }

            }

        }

        return 0;

    }

};
