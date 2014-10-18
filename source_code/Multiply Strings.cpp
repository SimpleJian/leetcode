class Solution {

public:

    string add(string num1, string num2){

        reverse(num1.begin(), num1.end());

        reverse(num2.begin(), num2.end());

        int c = 0;

        string sum;

        for(int i=0; i<num1.length() || i<num2.length(); i++){

            int a = i<num1.length() ? num1[i]-'0' : 0;

            int b = i<num2.length() ? num2[i]-'0' : 0;

            c += a+b;

            sum += '0' + c%10;

            c /= 10;

        }

        if(c)   sum += '0'+c;

        reverse(sum.begin(), sum.end());

        return sum;

    }

    string mul(string num1, int d){

        reverse(num1.begin(), num1.end());

        string ans;

        int c = 0;

        for(int i=0; i<num1.length(); i++){

            c += d * (num1[i]-'0');

            ans += '0' + c%10;

            c /= 10;

        }

        if(c)   ans += '0'+c;

        reverse(ans.begin(), ans.end());

        return ans;

    }

    string mul10(string num){

        return num+'0';

    }

    string multiply(string num1, string num2) {

        string ans(1, '0');

        for(int i=0; i<num2.length(); i++){

            ans = mul10(ans);

            ans = add(ans, mul(num1, num2[i]-'0'));

        }

        int start = 0;

        while(start<ans.length() && ans[start]=='0')    start++;

        if(start<ans.length())  return ans.substr(start);

        else    return "0";

    }

};
