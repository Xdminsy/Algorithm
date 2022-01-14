class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](const auto& x, const auto& y){
            return x[1] < y[1];
        });
        int r = 0, a = 0;
        for(int i = 0; i < points.size(); ++i){
            if(r == 0 || points[i][0] > a){
                ++r;
                a = points[i][1];
            }
        }
        return r;
    }
};
