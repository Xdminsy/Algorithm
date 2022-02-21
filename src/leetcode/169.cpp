#include "headers.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, p;
        for(int i: nums){
            if(count == 0)
                p = i;
            if(p == i) ++count;
            else --count;
        }
        return p;
    }
};
