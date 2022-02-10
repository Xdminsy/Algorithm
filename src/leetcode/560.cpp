#include <vector>
#include <unordered_map>

using ::std::vector, ::std::unordered_map;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m{{0, 1}};
        int vsum = 0, result = 0;
        for(int num: nums){
            vsum += num;
            if(m.count(vsum - k)){
                result += m[vsum - k];
            }
            ++m[vsum];
        }
        return result;
    }
};
