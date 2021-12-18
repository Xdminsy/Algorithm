class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = size(edges), i;
        auto count = make_unique<int[]>(n + 2);
        for(const auto& v: edges){
            ++count[v[0]];
            ++count[v[1]];
        }
        for(i = 0; i <= n + 1; ++i)
            if(count[i] == n)
                break;
        return i;
    }
};