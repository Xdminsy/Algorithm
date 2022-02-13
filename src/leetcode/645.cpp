#include "headers.h"

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size(), r = 0;
        for(int i = 0; i < len; ++i){
            r ^= (i + 1) ^ nums[i];
        }
        int rightmost = r & ~(r - 1);
        int x = 0, y = 0;
        for(int i = 0; i < len; ++i){
            if(nums[i] & rightmost){
                x ^= nums[i];
            } else {
                y ^= nums[i];
            }
            if((i + 1) & rightmost){
                x ^= i + 1;
            } else {
                y ^= i + 1;
            }
        }
        for(int num: nums){
            if(num == x){
                return {x, y};
            }
        }
        return {y, x};
    }
};
