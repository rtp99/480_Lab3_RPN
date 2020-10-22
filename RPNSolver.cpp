#include "RPNSolver.h"

double RPNSolver::solveRPN(std::vector<std::string> RPN) {
    std::stack<float> op_stack;
    op_stack.push(0);
    std::vector<std::string>::iterator itr = RPN.begin();
    double op1, op2;
    for (itr = RPN.begin(); itr != RPN.end(); itr++) {
        // we only have to check if the last character in the string is a digit
        // the parser automatically separates digits from non digits
        // because negative signs exist, we check the last digit
        if(isdigit((*itr)[itr->size() - 1])) {
            op_stack.push(std::stod(*itr));
        }
        else if (*itr == "+"){
            op2 = op_stack.top();
            op_stack.pop();
            op1 = op_stack.top();
            op_stack.pop();
            op_stack.push(op1 + op2);
        }
        else if (*itr == "-"){
            op2 = op_stack.top();
            op_stack.pop();
            op1 = op_stack.top();
            op_stack.pop();
            op_stack.push(op1 - op2);
        }
        else if (*itr == "*"){
            op2 = op_stack.top();
            op_stack.pop();
            op1 = op_stack.top();
            op_stack.pop();
            op_stack.push(op1 * op2);

        }
        else if (*itr == "/"){
            op2 = op_stack.top();
            op_stack.pop();
            op1 = op_stack.top();
            op_stack.pop();
            op_stack.push(op1 / op2);
        }
        else if (*itr == "^"){
                op2 = op_stack.top();
                op_stack.pop();
                op1 = op_stack.top();
                op_stack.pop();
                op_stack.push(pow(op1, op2));
        }
        else if (*itr == "sin"){
                op1 = op_stack.top();
                op_stack.pop();
                op_stack.push(sin(op1));
        }
        else if (*itr == "cos"){
                op1 = op_stack.top();
                op_stack.pop();
                op_stack.push(cos(op1));
        }
        else if (*itr == "tan"){
                op1 = op_stack.top();
                op_stack.pop();
                op_stack.push(tan(op1));
        }
        else if (*itr == "cot"){
                op1 = op_stack.top();
                op_stack.pop();
                op_stack.push(cos(op1) / sin(op1));
        }
        else if (*itr == "ln"){
                op1 = op_stack.top();
                op_stack.pop();
                op_stack.push(log(op1));
        }
        else if (*itr == "log"){
                op1 = op_stack.top();
                op_stack.pop();
                op_stack.push(log10(op1));
        }

    }
    return op_stack.top();
}
