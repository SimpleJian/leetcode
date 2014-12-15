class Solution {

public:

    void solve(vector<vector<char>> &board) {

        int n = board.size();

        if(n<1) return;

        int m = board[0].size();

        queue<pair<int, int> > Q;

        for(int i=0; i<n; i++){

            if(board[i][0]=='O')    Q.push(make_pair(i, 0)), board[i][0] = 'o';

            if(board[i][m-1]=='O')  Q.push(make_pair(i, m-1)), board[i][m-1] = 'o';

        }

        for(int j=0; j<m; j++){

            if(board[0][j]=='O')    Q.push(make_pair(0, j)), board[0][j] = 'o';

            if(board[n-1][j]=='O')  Q.push(make_pair(n-1, j)), board[n-1][j] = 'o';

        }

        int dx[] = {0, 0, 1, -1};

        int dy[] = {-1, 1, 0, 0};

        while(!Q.empty()){

            pair<int, int> u = Q.front();

            Q.pop();

            for(int k=0; k<4; k++){

                int i = u.first+dx[k];

                int j = u.second+dy[k];

                if(i>=0 && i<n && j>=0 && j<m && board[i][j]=='O')  Q.push(make_pair(i, j)), board[i][j] = 'o';

            }

        }

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                if(board[i][j]=='O')    board[i][j] = 'X';

            }

        }

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                if(board[i][j]=='o')    board[i][j] = 'O';

            }

        }

    }

};
