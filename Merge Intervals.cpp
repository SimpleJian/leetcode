/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
inline bool operator<(const Interval& a, const Interval& b)
{
    return a.start < b.start;
}
class Solution {
public:
    bool overlaps(Interval a, Interval b){
        return !(a.end<b.start || b.end<a.start);
    }
    Interval merge(Interval a, Interval b){
        int start = min(a.start, b.start);
        int end = max(a.end, b.end);
        return Interval(start, end);
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        if(0==n)    return intervals;
        vector<Interval> ans;
        Interval last = intervals[0];
        for(int i=0; i<n; i++){
            if(overlaps(last, intervals[i])){
                last = merge(last, intervals[i]);
            }
            else{
                if(last.end<intervals[i].start){
                    ans.push_back(last);
                    last = intervals[i];
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        ans.push_back(last);
        return ans;
    }
};
