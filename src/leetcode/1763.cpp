#include "headers.h"

// O(n^2) brute force.
class Solution {
public:
    string longestNiceSubstring(string s) {
        int sz = size(s), maxlen = 0, resbegin = 0, p, k;
        int state[26];
        char c;
        for(int i = 0; i < sz; ++i){
            memset(state, 0, sizeof(state));
            k = 0;
            for(int j = i; j < sz; ++j){
                c = s[j];
                p = tolower(c) - 'a';
                if(state[p] == 0){
                    ++k;
                    state[p] = 1 + !!islower(c);
                } else if(state[p] == 1 && islower(c) || state[p] == 2 && isupper(c)){
                    state[p] = 3;
                    --k;
                }
                if(!k && j - i + 1 > maxlen){
                    maxlen = j - i + 1;
                    resbegin = i;
                }
            }
        }
        return s.substr(resbegin, maxlen);
    }
};

int main(){
    Solution solution;
    cout << solution.longestNiceSubstring("c");
}