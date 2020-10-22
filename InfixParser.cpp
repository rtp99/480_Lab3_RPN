#include "InfixParser.h"

std::vector<std::string> InfixParser::parseString(std::string infix) {
    std::stack<char> proc_stack;            // stack by which we process the input
    proc_stack.push('\0');               // '\0' is our end-of-stack marker
    std::vector<std::string> output_vec;    // output vector to hold final data
    std::string::iterator input_itr;

    std::string dig_acc = "";   // digit accumulator, used for combining individual digits into full numbers
    std::string func_acc = "";  // function accumulator, used for combining characters of functions into their full name
    for (input_itr = infix.begin(); input_itr != infix.end(); input_itr++) {
        // ignore whitespace
        if(*input_itr == ' ') {}
        // ignore equals signs at the end of equations
        else if (*input_itr == '=' && *input_itr == *--infix.end()) {}
            // if current character is a digit, collect all digits in final number, and push to output vector
        else if (isdigit(*input_itr)) {
            while (isdigit(*input_itr)) {
                dig_acc.push_back(*input_itr);
                input_itr++;
            }
            output_vec.push_back(dig_acc);
            dig_acc = "";
            input_itr--;
        }
            // if current character is a letter, collect all letters to produce final function name
        else if (isalpha(*input_itr)) {
            while (isalpha(*input_itr)) {
                func_acc.push_back(*input_itr);
                input_itr++;
            }
            output_vec.push_back(func_acc);
            func_acc = "";
            input_itr--;
        }
            //if current character is an open paren, push to stack
        else if (*input_itr == '(') {
            proc_stack.push(*input_itr);
        } else if (*input_itr == ')') {
            while (proc_stack.top() != '\0' && proc_stack.top() != '(') {
                char top = proc_stack.top();
                proc_stack.pop();
                output_vec.emplace_back(1, top);
            }
            if (proc_stack.top() == '(') {
                // if there is a negative sign with no operand, this open paren is its operand
                if (dig_acc == "-")
                    output_vec.emplace_back(1, '-');
                char top = proc_stack.top();
                proc_stack.pop();
            }
        } else if (isOperator(*input_itr)) {
            if (*input_itr != '-' || (*input_itr == '-' && dig_acc == "-")) {
                while (proc_stack.top() != '\0' && getPrecedence(*input_itr) <= getPrecedence(proc_stack.top())) {
                    char top = proc_stack.top();
                    proc_stack.pop();
                    output_vec.emplace_back(1, top);
                }
                proc_stack.push(*input_itr);
            } else {
                dig_acc.push_back('-');
            }
        } else {
            // TODO:THROW EXCEPTION
            std::string error = "invalid character ";
            error.push_back(*input_itr);
            throw error;
        }
    }
    while (proc_stack.top() != '\0') {
        char top = proc_stack.top();
        proc_stack.pop();
        output_vec.emplace_back(1, top);
    }
    return output_vec;
}

bool InfixParser::isOperator(char input) {
    return (input == '*' || input == '/' || input == '+' || input == '-' || input == '^');
}

int InfixParser::getPrecedence(char input) {
    if (input == '^')
        return 3;
    else if (input == '*' || input == '/')
        return 2;
    else if (input == '+' || input == '-')
        return 1;
    else
        return -1;
}

