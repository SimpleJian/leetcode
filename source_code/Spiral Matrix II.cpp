class Solution {

public:

    vector<vector<int> > generateMatrix(int n) {

        vector<vector<int> > ans(n, vector<int>(n, 0));

        int left=0, right=n, top=0, down=n;

        int cur = 0;

        while(cur<n*n){

            if(left+1==right){

                ans[top][left] = ++cur;

            }

            for(int j=left; j<right-1; j++) ans[top][j] = ++cur;

            for(int i=top; i<down-1; i++)   ans[i][right-1] = ++cur;

            for(int j=right-1; j>left; j--) ans[down-1][j] = ++cur;

            for(int i=down-1; i>top; i--)   ans[i][left] = ++cur;

            left++, right--, top++, down--;

        }

        return ans;

    }

};
