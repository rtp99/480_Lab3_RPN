#include <iostream>
#include "InfixParser.h"
#include "RPNSolver.h"

int main() {
    InfixParser parser;
    RPNSolver solver;
    bool breakOut = false;

    while (!breakOut) {

        std::cout << "> ";
        std::cout.flush();
        std::string input;
        std::getline(std::cin, input);

        try {
            std::vector<std::string> infix = parser.parseString(input);
            double output = solver.solveRPN(infix);
            std::cout << output << std::endl;
        } catch (std::string e) {
            std::cout << e << std::endl;
        }

    }
    return 0;
}
