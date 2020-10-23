#include "InfixParser.h"

std::vector<std::string> InfixParser::parseString(std::string infix) {
    std::stack<std::string> proc_stack;     // stack by which we process the input
    proc_stack.push("\0");               // '\0' is our end-of-stack marker
    std::vector<std::string> output_vec;    // output vector to hold final data
    std::string::iterator input_itr;

    std::string dig_acc = "";   // digit accumulator, used for combining individual digits into full numbers
    std::string func_acc = "";  // function accumulator, used for combining characters of functions into their full name
    bool neg_flag = true;       // negation flag, is true when the next token could possibly be a negative sign
    for (input_itr = infix.begin(); input_itr != infix.end(); input_itr++) {
        // ignore whitespace
        if (*input_itr == ' ') {}
            // ignore equals signs at the end of equations
        else if (*input_itr == '=' && *input_itr == *--infix.end()) {}
            // if current character is a digit, collect all digits in final number, and push to output vector
            // handles decimal places
        else if (isdigit(*input_itr) || *input_itr == '.') {
            int decimal_counter = 0;
            while (isdigit(*input_itr) || *input_itr == '.') {
                if (*input_itr == '.')
                    decimal_counter++;
                if (decimal_counter > 1) {
                    std::string error = "invalid character . too many decimals";
                    throw error;
                }
                dig_acc.push_back(*input_itr);
                input_itr++;
            }
            output_vec.push_back(dig_acc);
            dig_acc = "";
            input_itr--;
            neg_flag = false;
        }
            // if current character is a letter, collect all letters to produce final function name
        else if (isalpha(*input_itr)) {
            while (isalpha(*input_itr)) {
                func_acc.push_back(*input_itr);
                input_itr++;
            }
            proc_stack.push(func_acc);
            func_acc = "";
            input_itr--;
            neg_flag = false;
        }
            //if current character is an open paren, push to stack
        else if (*input_itr == '(') {
            proc_stack.push(std::string(1, *input_itr));
            neg_flag = true;
        } else if (*input_itr == ')') {
            while (proc_stack.top() != "\0" && proc_stack.top() != "(") {
                std::string top = proc_stack.top();
                proc_stack.pop();
                output_vec.emplace_back(top);
            }
            if (proc_stack.top() == "(") {
                proc_stack.pop();
            } else {
                std::string error = "incorrect syntax )";
                throw error;
            }
            neg_flag = false;
        } else if (isOperator(*input_itr)) {
            if(neg_flag && *input_itr == '-') {
                proc_stack.push("neg");
                neg_flag = true;
            } else {
                while (proc_stack.top() != "\0" && getPrecedence(*input_itr) <= getPrecedence(proc_stack.top()[0])) {
                    std::string top = proc_stack.top();
                    proc_stack.pop();
                    output_vec.emplace_back(top);
                }
                neg_flag = true;
                proc_stack.push(std::string(1, *input_itr));
            }
        } else {
            // TODO:THROW EXCEPTION
            std::string error = "invalid character ";
            error.push_back(*input_itr);
            throw error;
        }
    }
    while (proc_stack.top() != "\0") {
        std::string top = proc_stack.top();
        proc_stack.pop();
        output_vec.emplace_back(top);
    }
    return output_vec;
}

bool InfixParser::isOperator(char input) {
    return (input == '*' || input == '/' || input == '+' || input == '-' || input == '^');
}

int InfixParser::getPrecedence(char input) {
    if (isalpha(input))
        return 4;
    else if (input == '^')
        return 3;
    else if (input == '*' || input == '/')
        return 2;
    else if (input == '+' || input == '-')
        return 1;
    else
        return -1;
}

