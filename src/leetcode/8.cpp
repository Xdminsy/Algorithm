#include "headers.h"

class Solution {
public:
    int myAtoi(string s) {
        int p = 0, sz = s.size(), r = 0, sign = 1, d;
        while(p < sz && s[p] == ' ') ++p;
        if(p < sz && (s[p] == '-' || s[p] == '+')){
            if(s[p] == '-')
                sign = -1;
            ++p;
        }
        while(p < sz){
            if(isdigit(s[p])){
                d = s[p] - '0';
                if(sign == 1 && r > (INT_MAX - d) / 10) return INT_MAX;
                if(sign == -1 && r < (INT_MIN + d) / 10) return INT_MIN;
                r = r * 10 + sign * d;
            } else break;
            ++p;
        }
        return r;
    }
};
