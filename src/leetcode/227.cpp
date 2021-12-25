class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        istringstream iss(s);
        int x, r = 0;
        char op;
        iss >> x;
        nums.push(x);
        while(iss >> op >> x){
            if(op == '*'){
                x = nums.top() * x;
                nums.pop();
                nums.push(x);
            }else if(op == '/'){
                x = nums.top() / x;
                nums.pop();
                nums.push(x);
            }else if(op == '+' || op == '-'){
                nums.push(x);
                ops.push(op);
            }
        }
        while(!ops.empty()){
            x = nums.top();
            nums.pop();
            if(ops.top() == '+') r += x;
            else r -= x;
            ops.pop();
        }
        return r + nums.top();
    }
};
