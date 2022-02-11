#include <string>

using ::std::string;

class Solution {
    template<size_t s>
    bool all_zero(int (&arr)[s]){
        for(size_t i = 0; i < s; ++i)
            if(arr[i] != 0)
                return false;
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        int m[26] = {0}, len1 = s1.size(), len2 = s2.size();
        for(char c: s1){
            ++m[c - 'a'];
        }
        for(int i = 0; i < len1; ++i){
            --m[s2[i] - 'a'];
        }
        if(all_zero(m))
            return true;
        for(int i = len1; i < len2; ++i){
            --m[s2[i] - 'a'];
            ++m[s2[i - len1] - 'a'];
            if(all_zero(m))
                return true;
        }
        return false;
    }
};