class Solution {
public:
    int findComplement(int num) {
        int b = 0, result = 0;
        while(num){
            result |= (num & 1 ^ 1) << b;
            ++b;
            num >>= 1;
        }
        return result;
    }
};
