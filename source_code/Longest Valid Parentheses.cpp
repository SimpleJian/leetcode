class Solution {

public:

    int longestValidParentheses(string s) {

        int n = s.length();

        vector<int> f(n, 0);

        stack<char> stk;

        for(int i=0; i<n; i++){

            if(stk.empty()) {

                f[i] = 0;

                stk.push(s[i]);

            }

            else{

                char c = stk.top();

                if(c=='(' && s[i]==')'){

                    f[i] = f[i-1] + 2;

                    if(i>=f[i]) f[i] += f[i-f[i]];

                    stk.pop();

                }

                else{

                    f[i] = 0;

                    stk.push(s[i]);

                }

            }

        }

        int ans = 0;

        for(int i=0; i<n; i++){

            ans = max(ans, f[i]);

        }

        return ans;

    }

};
