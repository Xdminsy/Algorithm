#include "headers.h"

class Solution {
public:
    string addBinary(string a, string b) {
        stringstream ss;
        int sa = a.size(), sb = b.size();
        int pa = sa - 1, pb = sb - 1;
        int carry = 0, sum = 0;
        while(pa >= 0 || pb >= 0 || carry){
            sum = carry;
            if(pa >= 0) sum += a[pa--] - '0';
            if(pb >= 0) sum += b[pb--] - '0';
            carry = sum > 1;
            sum &= 1;
            ss.put(sum + '0');
        }
        string s{ss.str()};
        return string(s.rbegin(), s.rend());
    }
};
