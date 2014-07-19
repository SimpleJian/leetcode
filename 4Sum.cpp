struct MyListNode{
    int i, j;
    MyListNode *next;
    MyListNode(int x, int y, MyListNode *p) : i(x), j(y), next(p) {}
};
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        map<int, MyListNode*> m;
        int n = num.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int s = num[i] + num[j];
                if(m.end() != m.find(s)){
                    m[s] = new MyListNode(i, j, m[s]);
                }
                else{
                    m[s] = new MyListNode(i, j, NULL);
                }
            }
        }
        vector<vector<int> > ans;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int s = target - num[i] - num[j];
                if(m.end() != m.find(s)){
                    MyListNode *p = m[s];
                    while(NULL != p){
                        if((p->i) > j){
                            vector<int> t(4, 0);
                            t[0] = num[i];
                            t[1] = num[j];
                            t[2] = num[p->i];
                            t[3] = num[p->j];
                            sort(t.begin(), t.end());
                            ans.push_back(t);
                        }
                        p = p->next;
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        vector<vector<int> >::iterator it;
        it = unique(ans.begin(), ans.end());
        if(ans.end() != it){
            ans.erase(it, ans.end());
        }
        return ans;
    }
};
