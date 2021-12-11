#include "headers.h"

class Solution {
public:
    bool check(vector<int>& nums) {
        int pos = 1, sz = size(nums);
        while(pos < sz && nums[pos - 1] <= nums[pos]) ++pos;
        if(pos++ == sz) return true; // if(pos == sz) return true; else ++pos;
        while(pos < sz && nums[pos - 1] <= nums[pos]) ++pos;
        return pos == sz && nums[sz - 1] <= nums[0];
    }
};