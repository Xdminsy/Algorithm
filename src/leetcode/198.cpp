#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 2) return nums.front();
        int dp[101] = {nums[0], max(nums[0], nums[1])}, s = size(nums);
        for(int i = 2; i < s; ++i)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        return dp[s - 1];
    }
};

int main(){
    Solution solution;
    vector<int> v{1, 2, 3, 1};
    cout << solution.rob(v) << endl;
}