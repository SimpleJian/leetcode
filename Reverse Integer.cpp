class Solution {
public:
    int reverse(int x) {
        int s = x>=0 ? 1 : -1;
        int y = 0;
        x *= s;
        while(x){
            y *= 10;
            y += x%10;
            x /= 10;
        }
        return s*y;
    }
};
