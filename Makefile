main.o : main.cpp InfixParser.h RPNSolver.h
        g++ -c main.cpp
InfixParser.o : InfixParser.cpp InfixParser.h 
        g++ -c InfixParser.cpp
RPNSolver.o : RPNSolver.cpp RPNSolver.h 
        g++ -c RPNSolver.cpp
clean :
        rm edit main.o RPNSolver.o InfixParser.o