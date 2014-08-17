class Solution {
public:
    void reverseWords(string &s) {
        stack<string> wordStack;
        int n = s.length();
        int i=0, j=0;
        while(i<n){
            for(; i<n; i++){
                if(s[i]!=' ')   break;
            }
            for(j=i; j<n; j++){
                if(' '==s[j])   break;
            }
            if(i>=n)    break;
            wordStack.push(s.substr(i, j-i));
            i = j;
        }
        s = "";
        bool first = 1;
        while(!wordStack.empty()){
            string word = wordStack.top();
            wordStack.pop();
            if(!first)  s += ' ';
            else    first = 0;
            s += word;
        }
    }
};
