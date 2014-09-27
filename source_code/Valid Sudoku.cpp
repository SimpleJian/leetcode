class Solution {

public:

    bool check_row(int i, vector<vector<char> > &map){

        vector<int> f(10, 0);

        for(int j=0; j<9; j++){

            if(map[i][j]=='.')  continue;

            int t = map[i][j] - '0';

            if(f[t])    return 0;

            f[t] = 1;

        }

        return 1;

    }

    bool check_col(int j, vector<vector<char> > &map){

        vector<int> f(10, 0);

        for(int i=0; i<9; i++){

            if(map[i][j]=='.')  continue;

            int t = map[i][j] - '0';

            if(f[t])    return 0;

            f[t] = 1;

        }

        return 1;

    }

    bool check_sub(int k, vector<vector<char> > &map){

        int top = k/3 * 3, left = k%3 * 3;

        vector<int> f(10, 0);

        for(int i=top; i<top+3; i++){

            for(int j=left; j<left+3; j++){

                if(map[i][j]=='.')  continue;

                int t = map[i][j] - '0';

                if(f[t])    return 0;

                f[t] = 1;

            }

        }

        return 1;

    }

    bool isValidSudoku(vector<vector<char> > &board) {

        for(int i=0; i<9; i++){

            if(0==check_row(i, board))  return 0;

            if(0==check_col(i, board))  return 0;

            if(0==check_sub(i, board))  return 0;

        }

        return 1;

    }

};
