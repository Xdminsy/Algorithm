class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        int result = 0, exp = 0;
        while(n){
            result |= !(n & 1) << exp;
            n >>= 1;
            ++exp;
        }
        return result;
    }
};
