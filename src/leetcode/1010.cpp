#include "headers.h"

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count[60]{0}, result{0};
        for(int i: time){
            ++count[i % 60];
        }
        for(int i = 1; i < 30; ++i){
            result += count[i] * count[60 - i];
        }
        return result + count[0] * (count[0] - 1) / 2 + count[30] * (count[30] - 1) / 2;
    }
};
