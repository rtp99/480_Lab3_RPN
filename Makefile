main.o: main.cpp InfixParser.h InfixParser.cpp RPNSolver.h RPNSolver.cpp
	g++ -c -std=c++11 main.cpp InfixParser.cpp RPNSolver.cpp
InfixParser.o: InfixParser.h InfixParser.cpp
	g++ -c -std=c++11 InfixParser.cpp
RPNSolver.o: RPNSolver.h RPNSolver.cpp
	g++ -c -std=c++11 RPNSolver.cpp
lab3: main.o InfixParser.o RPNSolver.o	
	g++ -std=c++11 main.o InfixParser.o RPNSolver.o -o lab3
clean:
	rm *.o
