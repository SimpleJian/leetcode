class Solution {

public:

    string minWindow(string S, string T) {

        vector<int> count(130, 0);

        for(int i=0; i<T.length(); i++) count[T[i]]++;

        int match = 0;

        int min_len = S.length()+1;

        string ans = "";

        for(int i=0, j=0; i+T.length()-1<S.length(); ){

            while(j<S.length() && match<T.length()){

                if(count[S[j]]>0)   match++;

                count[S[j]]--;

                j++;

            }

            if(match<T.length())    break;

            while(match==T.length()){

                if(count[S[i]]==0)  match--;

                count[S[i]]++;

                i++;

            }

            if(j-i+1 < min_len){

                min_len = j-i+1;

                ans = S.substr(i-1, min_len);

            }

        }

        return ans;

    }

};
