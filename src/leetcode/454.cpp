#include <vector>
#include <unordered_map>

using ::std::vector, ::std::unordered_map;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int result = 0;
        unordered_map<int, int> m;
        for(int x: nums1)
            for(int y: nums2)
                ++m[x + y];
        for(int x: nums3)
            for(int y: nums4)
                result += m[-(x + y)];
        return result;
    }
};
