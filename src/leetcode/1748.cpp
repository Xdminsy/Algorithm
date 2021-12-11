#include "headers.h"

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n[101] = {0}, sum = 0;
        for(int num: nums){
            if(n[num] == 0){
                sum += num;
                n[num] = 1;
            } else if(n[num] == 1){
                sum -= num;
                n[num] = 2;
            }
        }
        return sum;
    }
};