#include <vector>

using ::std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int n: nums)
            if(i < 2 || n > nums[i - 2])
                nums[i++] = n;
        return i;
    }
};

class SolutionFirst {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size(), p = 0, c = 1;
        for(int i = 1; i < len; ++i){
            if(nums[i] == nums[p]){
                ++c;
            } else {
                c = 1;
            }
            if(c <= 2){
                nums[++p] = nums[i];
            }
        }
        return p + 1;
    }
};
