// reverse Polish notation, the binary operator follows operands,
// use a stack to store all operands, when an operator is met, take two operands from stack, compute them
// and then push the result into the stack
// #include <string>   // for stoi
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/") {
                int op_2 = s.top();  // ------------
                s.pop();
                int op_1 = s.top();   // --------------
                s.pop();
                if (tokens[i] == "+") s.push(op_1+op_2);  // ----------
                else if (tokens[i] == "-") s.push(op_1-op_2);
                else if (tokens[i] == "*") s.push(op_1*op_2);
                else s.push(op_1/op_2);
            } else s.push(str2int(tokens[i]));   // here can be stoi(tokens[i])
        }
        return s.top();
    }
private:
    int str2int(string str) {
        int res = 0;
        int sign = 1, i = 0;
        if (str[0] == '-') {
            sign = -1;
            i = 1;
        } else if (str[0] == '+')
            i = 1;
        for (; i < str.size(); i++) res = res*10 + str[i]-'0';
        return sign*res;
    }
};


// based on the solution of hercule24, https://discuss.leetcode.com/topic/38178/fancy-c-lambda-expression-solution
// use lambda expression to get corresponding function for a operator
// #include <functional>  // for function<>
// #include <map> // for map
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;       // function<return type <arg_1 type, arg_2 type>>
        map<string, function<int (int, int)>> op2func = {   // the map initialization, {{key, value}, {key, value}};
            {"+", [](int a, int b) {return a+b;}},
            {"-", [](int a, int b) {return a-b;}},
            {"*", [](int a, int b) {return a*b;}},
            {"/", [](int a, int b) {return a/b;}}
        };
        
        for (string str:tokens) {
            if (op2func.count(str)) { // --------------------
                int op_2 = s.top();
                s.pop();
                int op_1 = s.top();
                s.pop();
                s.push(op2func[str](op_1, op_2));
            } else s.push(stoi(str));
        }
        return s.top();
    }
};