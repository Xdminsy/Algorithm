class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, d = 0, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        for(int i = 0; i < 4; ++i){
            for(char c: instructions){
                if(c == 'G'){
                    x += dx[d];
                    y += dy[d];
                } else if(c == 'L'){
                    --d;
                } else if(c == 'R'){
                    ++d;
                }
                d= (d + 4) % 4;
            }
        }
        return x == 0 && y == 0;
    }
};
