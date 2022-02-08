class Solution {
public:
    int addDigits(int num) {
        int t = 0;
        while(num > 9){
            t = 0;
            while(num){
                t += num % 10;
                num /= 10;
            }
            num = t;
        }
        return num;
    }
};
