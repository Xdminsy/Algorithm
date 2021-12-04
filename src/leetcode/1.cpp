#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0, s = size(nums); i < s; ++i){
            if(m.count(target - nums[i]))
                return {i, m[target - nums[i]]};
            m[nums[i]] = i;
        }
        return {0, 1};
    }
};