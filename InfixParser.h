#ifndef INC_480_LAB3_RPN_INFIXPARSER_H
#define INC_480_LAB3_RPN_INFIXPARSER_H

#include <string>
#include <stack>
#include <vector>
#include <sstream>

class InfixParser {
public:
    std::vector<std::string> parseString(std::string infix);
private:
    static bool isOperator(char input);
    static int getPrecedence(char input);
};


#endif //INC_480_LAB3_RPN_INFIXPARSER_H
