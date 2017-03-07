/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool myFunction(Interval &a, Interval &b) {   // self comparison function, here & is not a must, but just < , if 
    return a.start < b.start;                 // <= there will be runtime error
}
// sort Interval first, then start by beginning the first Interval
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), myFunction);
        
        vector<Interval> res;
        
        Interval tmp(intervals[0]);
        for (int i = 1; i < n; i++) {
            if (intervals[i].start > tmp.end) {   // tmp is over, start a new one
                res.push_back(tmp);
                tmp = intervals[i];
            }else if (intervals[i].end > tmp.end) tmp.end = intervals[i].end;
        }
        res.push_back(tmp);
        
        return res;
    }
};

// here is comparison function related 
// http://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects
// http://stackoverflow.com/questions/16894700/c-custom-compare-function-for-stdsort



// based on the solution of lchen77, https://discuss.leetcode.com/topic/20263/c-10-line-solution-easing-understanding
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){return a.start < b.start;}); // lambda expression(c++11)
        
        vector<Interval> res;
        res.push_back(intervals[0]);  // push_back first
        for (int i = 1; i < n; i++)
            if (res.back().end < intervals[i].start) res.push_back(intervals[i]);
            else res.back().end = max(res.back().end, intervals[i].end); // just max, no comparison
        return res;
    }
};