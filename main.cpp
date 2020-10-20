#include <iostream>
#include "InfixParser.h"

int main() {
    InfixParser parser;
    try {
        parser.parseString("-6-(-%%1)--1/-2*-2+-1");
    } catch (std::string e) {
        std::cout << e;
    }
    return 0;
}
