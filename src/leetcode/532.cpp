#include <vector>
#include <unordered_set>

using ::std::vector, ::std::unordered_set;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> s, dup;
        int result = 0;
        for(int num: nums){
            if(!s.count(num)){
                s.insert(num);
                if(k != 0){
                    result += s.count(num - k) + s.count(num + k);
                }
            } else if(k == 0) {
                dup.insert(num);
            }
        }
        return k == 0 ? dup.size() : result;
    }
};
