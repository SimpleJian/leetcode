<F9>class Solution {

public:

    vector<int> spiralOrder(vector<vector<int> > &matrix) {

        vector<int> ans;

        int n = matrix.size();

        if(n<1) return ans;

        int m = matrix[0].size();

        if(m<1) return ans;

        int l = 0, r = m;

        int u = 0, d = n;

        while(r-l>1 && d-u>1){

            for(int j=l; j<r-1; j++)  ans.push_back(matrix[u][j]);

            for(int i=u; i<d-1; i++)    ans.push_back(matrix[i][r-1]);

            for(int j=r-1; j>l; j--)   ans.push_back(matrix[d-1][j]);

            for(int i=d-1; i>u; i--)    ans.push_back(matrix[i][l]);

            l++, r--;

            u++, d--;

        }

        if(r-l>1 && d-u==1)   for(int j=l; j<r; j++)  ans.push_back(matrix[u][j]);

        else if(d-u>1 && r-l==1)   for(int i=u; i<d; i++)  ans.push_back(matrix[i][l]);

        else if(l+1==r && u+1==d)  ans.push_back(matrix[u][l]);

        return ans;

    }

};
