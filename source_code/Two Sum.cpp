class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> position;
        for(int i=0; i<numbers.size(); i++){
            int x = numbers[i];
            position[x] = i;
        }
        for(int i=0; i<numbers.size(); i++){
            int x = numbers[i];
            int y = target-x;
            if(position.end() != position.find(y)){
                int j = position[y];
                if(i^j){
                    int index1 = min(i, j)+1;
                    int index2 = max(i, j)+1;
                    vector<int> ret;
                    ret.push_back(index1);
                    ret.push_back(index2);
                    return ret;
                }
            }
        }
    }
};
