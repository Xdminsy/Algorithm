#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0, p2 = 0, sz1 = size(word1), sz2 = size(word2);
        ostringstream oss;
        while(p1 < sz1 && p2 < sz2){
            oss << word1[p1++];
            oss << word2[p2++];
        }
        oss.write(p1 < sz1 ? word1.data() + p1 : word2.data() + p2, sz2 - p2 + sz1 - p1);
        return oss.str();
    }
};

int main(){
    Solution solution;
    cout << solution.mergeAlternately("ab", "pq");
}