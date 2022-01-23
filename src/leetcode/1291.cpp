#include <vector>

using std::vector;

class Solution {
    int countDigits(int n){
        if(!n) return 1;
        int res = 0;
        while(n){
            ++res;
            n /= 10;
        }
        return res;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        int countLow = countDigits(low), countHigh = countDigits(high);
        vector<int> result;
        for(int i = countLow; i <= countHigh; ++i){
            int n = 0, k = 0;
            for(int j = 0; j < i; ++j){
                n = n * 10 + j + 1;
                k = k * 10 + 1;
            }
            for(int j = 0; j < 10 - i; ++j){
                if(n > high) return result;
                if(n >= low) result.push_back(n);
                n += k;
            }
        }
        return result;
    }
};
