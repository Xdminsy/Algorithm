#include <string>
#include <vector>

using std::vector, std::string;

class Solution {
    template<size_t sz>
    bool array_equal(int (&a)[sz], int (&b)[sz]){
        for(size_t i = 0; i < sz; ++i)
            if(a[i] != b[i])
                return false;
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int szs = s.size(), szp = p.size(), same = 1;
        if(szp > szs) return result;
        int mapp[26] = {0}, mapc[26] = {0};
        for(char c: p){ ++mapp[c - 'a']; }
        for(int i = 0; i < szp; ++i){
            ++mapc[s[i] - 'a'];
        }
        same = array_equal(mapp, mapc);
        if(same){
            result.push_back(0);
        }
        for(int i = szp; i < szs; ++i){
            if(same && s[i] == s[i - szp]){
                result.push_back(i - szp + 1);
            } else {
                --mapc[s[i - szp] - 'a'];
                ++mapc[s[i] - 'a'];
                if(same = array_equal(mapp, mapc)){
                    result.push_back(i - szp + 1);
                }
            }
        }
        return result;
    }
};
