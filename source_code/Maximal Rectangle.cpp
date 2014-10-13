class Solution {

public:

    int rectInHist(vector<int> &hist){

        hist.push_back(-1);

        stack<int> s;

        int ans = 0;

        for(int i=0; i<hist.size(); i++){

            while(!s.empty() && hist[i]<=hist[s.top()]){

                int h = hist[s.top()];

                s.pop();

                int w = s.empty() ? i : i-s.top()-1;

                ans = max(ans, w*h);

            }

            s.push(i);

        }

        return ans;

    }

    int maximalRectangle(vector<vector<char> > &matrix) {

        int n = matrix.size();

        if(n<1) return 0;

        int m = matrix[0].size();

        if(m<1) return 0;

        int ans = 0;

        vector<int> hist(m, 0);

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                if(matrix[i][j]=='1')   hist[j]++;

                else    hist[j] = 0;

            }

            ans = max(ans, rectInHist(hist));

        }

        return ans;

    }

};
