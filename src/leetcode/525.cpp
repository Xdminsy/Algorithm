#include <vector>
#include <unordered_map>
#include <algorithm>

using ::std::vector, ::std::unordered_map, ::std::max;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0, sum = 0, len = nums.size();
        unordered_map<int, int> m{{0, -1}};
        for(int i = 0; i < len; ++i){
            sum += nums[i] ? 1 : -1;
            if(m.count(sum)) result = max(result, i - m[sum]);
            else m[sum] = i;
        }
        return result;
    }
};
