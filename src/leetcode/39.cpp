#include "headers.h"

class Solution {
    void dfs(vector<int>& u, int target, vector<vector<int>>& result, vector<int>& current, int index){
        if(target == 0){
            result.push_back(current);
        }
        for(int i = index; i < u.size(); ++i){
            if(u[i] <= target){
                current.push_back(u[i]);
                dfs(u, target - u[i], result, current, i);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<int> us(candidates.begin(), candidates.end());
        vector<int> u(us.begin(), us.end());
        vector<vector<int>> result;
        vector<int> current;
        dfs(u, target, result, current, 0);
        return result;
    }
};
