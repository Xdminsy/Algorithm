#include <iostream>
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

int main() {
    Solution solution;
    vector<int> v{ 1, 2, 3, 4 };
    auto result = solution.twoSum(v, 3);
    cout << result[0] << ", " << result[1] << endl;
}