class Solution {

public:

    static const int N = 9*9*9 + 10;

    static const int M = 4*9*9 + 10;

    int u[N*5], d[N*5], l[N*5], r[N*5];

    int row[N*5], col[N*5];

    int sum_col[M], head[N];

    int node;

    void init(int n, int m){

        for(int i=1; i<=n; i++) head[i] = -1;

        for(int i=0; i<=m; i++){

            u[i] = d[i] = i;

            l[i] = i-1;

            r[i] = i+1;

            sum_col[i] = 0;

        }

        l[0] = m;

        r[m] = 0;

        node = m+1;

    }

    void add(int i, int j){

        row[node] = i;

        col[node] = j;

        sum_col[j]++;

        d[node] = d[j];

        u[d[node]] = node;

        d[j] = node;

        u[node] = j;

        if(-1==head[i]) head[i] = l[node] = r[node] = node;

        else{

            r[node] = r[head[i]];

            l[r[node]] = node;

            r[head[i]] = node;

            l[node] = head[i];

        }

        node++;

    }

    void del(int c){

        r[l[c]] = r[c];

        l[r[c]] = l[c];

        for(int i=d[c]; i^c; i=d[i]){

            for(int j=r[i]; j^i; j=r[j]){

                d[u[j]] = d[j];

                u[d[j]] = u[j];

                sum_col[col[j]]--;

            }

        }

    }

    void resume(int c){

        r[l[c]] = l[r[c]] = c;

        for(int i=u[c]; i^c; i=u[i]){

            for(int j=l[i]; j^i; j=l[j]){

                d[u[j]] = u[d[j]] = j;

                sum_col[col[j]]++;

            }

        }

    }

    void init_model(){

        init(9*9*9, 4*9*9);

        for(int i=0; i<9; i++){

            for(int j=0; j<9; j++){

                for(int k=0; k<9; k++){

                    int x = 81*i + 9*j + k + 1;

                    int y1 = 9*i + k + 1;

                    int y2 = 81 + 9*j + k + 1;

                    int y3 = 162 + 9*(i/3*3+j/3) + k + 1;

                    int y4 = 243 + 9*i + j + 1;

                    add(x, y1), add(x, y2), add(x, y3), add(x, y4);

                }

            }

        }

    }

    void choose(int x, vector<vector<char> > &board){

        x--;

        int k = x%9;

        int j = (x/9)%9;

        int i = x/81;

        board[i][j] = '1'+k;

    }

    bool dfs(int depth, vector<vector<char> > &board){

        if(0==r[0]) return 1;

        int t = N, c;

        for(int j=r[0]; j; j=r[j]){

            if(t>sum_col[j])    t = sum_col[c=j];

        }

        del(c);

        for(int i=d[c]; i^c; i=d[i]){

            for(int j=r[i]; j^i; j=r[j])    del(col[j]);

            choose(row[i], board);

            if(dfs(depth+1, board)) return 1;

            for(int j=l[i]; j^i; j=l[j])    resume(col[j]);

        }

        resume(c);

        return 0;

    }

    void solveSudoku(vector<vector<char> > &board) {

        init_model();

        for(int i=0; i<9; i++){

            for(int j=0; j<9; j++){

                if(board[i][j]=='.')    continue;

                int k = board[i][j] - '1';

                int y1 = 9*i + k + 1;

                int y2 = 81 + 9*j + k + 1;

                int y3 = 162 + 9*(i/3*3+j/3) + k + 1;

                int y4 = 243 + 9*i + j + 1;

                del(y1), del(y2), del(y3), del(y4);

            }

        }

        dfs(0, board);

    }

};
