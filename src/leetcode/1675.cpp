#include "headers.h"

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int, greater<int>> s;
        for(int x: nums){
            if(x % 2 == 0) s.insert(x);
            else s.insert(x * 2);
        }
        int minv = *s.begin() - *prev(s.end());
        while(*s.begin() % 2 == 0){
            s.insert(*s.begin() / 2);
            s.erase(s.begin());
            minv = min(minv, *s.begin() - *prev(s.end()));
        }
        return minv;
    }
};
