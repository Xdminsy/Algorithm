#include "headers.h"

static int io = [](){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        const int index = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
        return count_if(begin(items), end(items), [=](const vector<string>& v){
            return v[index] == ruleValue;
        });
    }
};
