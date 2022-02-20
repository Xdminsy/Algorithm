#include "headers.h"

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int prev = 0, result = 1;
        for(int i = 0; i < intervals.size(); ++i){
            if(intervals[i][0] > intervals[prev][0] && intervals[i][1] > intervals[prev][1]){
                ++result;
                prev = i;
            }
        }
        return result;
    }
};
