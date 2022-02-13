#include "headers.h"

class Solution {
    void dfs(vector<vector<int>>& result, vector<int>& nums, vector<int>& select, int depth){
        if(depth == nums.size()){
            result.push_back(select);
            return;
        }
        dfs(result, nums, select, depth + 1);
        select.push_back(nums[depth]);
        dfs(result, nums, select, depth + 1);
        select.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> select;
        dfs(result, nums, select, 0);
        return result;
    }
};
