class Solution {

public:

    int largestRectangleArea(vector<int> &height) {

        height.push_back(-1);

        stack<int> s;

        int ans = 0;

        for(int i=0; i<height.size(); i++){

            while(!s.empty() && height[i]<=height[s.top()]){

                int h = height[s.top()];

                s.pop();

                int w = s.empty() ? i : i-s.top()-1;

                ans = max(ans, h * w );

            }

            s.push(i);

        }

        return ans;

    }

};
