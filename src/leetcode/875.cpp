class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9, sz = piles.size();
        while(l <= r){
            int m = l + (r - l) / 2, t = 0;
            for(int i: piles)
                t += 1 + ((i - 1) / m);
            if(t <= h) r = m - 1;
            else l = m + 1;
        }
        return l;
    }
};
