#include "headers.h"

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(int n: num){
            while(!s.empty() && s.top() > n && k > 0){
                s.pop();
                --k;
            }
            if(!s.empty() || n != '0'){
                s.push(n);
            }
        }
        string r;
        while(!s.empty()){
            r = s.top() + r;
            s.pop();
        }
        if(r.empty() || k >= r.size()) return "0";
        return k ? r.substr(0, r.size() - k) : r;
    }
};
