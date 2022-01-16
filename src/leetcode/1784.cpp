class Solution {
public:
    bool checkOnesSegment(string s) {
        int state = -1, count = 0;
        for(char c: s){
            if(state == -1){
                state = c;
            }else if(state != c){
                state = c;
                if(++count > 1)
                    return false;
            }
        }
        return true;
    }
};
