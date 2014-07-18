/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ans;
        int n = intervals.size();
        bool processed = false;
        for(int i=0; i<n; i++){
            if(!processed){
                if(0==overlaps(intervals[i], newInterval)){
                    if(newInterval.end<intervals[i].start){
                        ans.push_back(newInterval);
                        ans.push_back(intervals[i]);
                        processed = true;
                    }
                    else{
                        ans.push_back(intervals[i]);
                    }
                }
                else{
                    newInterval = merge(newInterval, intervals[i]);
                }
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        if(!processed)  ans.push_back(newInterval);
        return ans;
    }
};
