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
        else  {if (*itr == "+"){
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

        }
        else if (*itr == "cos"){

        }
        else if (*itr == "tan"){

        }
        else if (*itr == "cot"){

        }
        else if (*itr == "ln"){

        }
        else if (*itr == "log"){

        }

    }
    return op_stack.top();
}
