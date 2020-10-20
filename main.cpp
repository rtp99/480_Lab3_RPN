#include "InfixParser.h"

int main() {
    InfixParser parser;
    parser.parseString("-6-(-1)--1/-2*-2+-1");
    return 0;
}
