class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size(), c = 1, r = 0;
        for(int i = 0; i < sz; ++i){
            if(flowerbed[i] == 0) {
                ++c;
            } else {
                r += (c - 1) / 2;
                c = 0;
            }
        }
        r += c / 2;
        return r >= n;
    }
};
