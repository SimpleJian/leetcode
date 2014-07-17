class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int> > d(n1+1, vector<int>(n2+1));
        for(int i=0; i<=n1; i++)    d[i][0] = i;
        for(int i=0; i<=n2; i++)    d[0][i] = i;
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(word1[i-1]==word2[j-1])  d[i][j] = d[i-1][j-1];
                else{
                    d[i][j] = 1+min(d[i-1][j-1], min(d[i-1][j], d[i][j-1]));
                }
            }
        }
        return d[n1][n2];
    }
};
