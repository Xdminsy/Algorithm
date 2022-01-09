#include "headers.h"

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int from[1005]{0}, to[1005]{0}, s = 0;
        for(const auto& trip: trips){
            from[trip[1]] += trip[0];
            to[trip[2]] += trip[0];
        }
        for(int i = 0; i < 1001; ++i){
            s += from[i] - to[i];
            if(s > capacity)
                return false;
        }
        return true;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> v{{9,3,4},{9,1,7},{4,2,4},{7,4,5}};
    solution.carPooling(v, 23);
}