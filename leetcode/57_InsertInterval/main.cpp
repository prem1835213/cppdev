#include <vector>
#include <iostream>

/*
    Given an array of non-overlapping intervals which are sorted according to the start.
    Insert an interval in the appropriate location, keeping the sorted property and merge
    overlapping interval if necessary.
*/

struct Interval{
    int start;
    int end;
    Interval(){}
    Interval(int s, int e) : start(s), end(e){}
};

class Solution{
public:
    
    void mergeOverlappingIntervals(std::vector<Interval>& intervals){
        int i = 0;
        while (i < intervals.size()){
            if (i+1 >= intervals.size()) return;
            if (intervals[i+1].start <= intervals[i].end){
                int maxEnd = std::max(intervals[i+1].end, intervals[i].end);
                intervals[i].end = maxEnd;
                intervals.erase(intervals.begin() + i+1);
            }
            else{
                i++;
            }
        }
        return;
    }

    void insertSingleInterval(std::vector<Interval>& intervals, Interval newInterval){
        int n = intervals.size();
        for (int i = 0; i < n; i++){
            if (newInterval.start < intervals[i].start){
                intervals.insert(intervals.begin() + i, newInterval);
                return;
            }
        }
        intervals.push_back(newInterval);
        return;
    }

    std::vector<Interval> insertAndMerge(std::vector<Interval>& intervals, Interval newInterval){
        insertSingleInterval(intervals, newInterval);
        mergeOverlappingIntervals(intervals);
        return intervals;
    }
};

int main(){
    Interval first = Interval(1, 7);
    Interval second = Interval(9, 12);
    Interval newInterval = Interval(5, 8);

    std::vector<Interval> intervals = {first, second};
    
    Solution sol;
    intervals = sol.insertAndMerge(intervals, newInterval);

    for (int i = 0; i < intervals.size(); i++){
        std::cout << intervals[i].start << " " << intervals[i].end << std::endl;
    }
}