execute_test: Connection.o DirectConnection.o Matrix.o DataBase.o execute_project_file.o RouteFinder.o FinderAlgorithm.o
	g++ -o project_test.out Connection.o DirectConnection.o Matrix.o DataBase.o execute_project_file.o RouteFinder.o FinderAlgorithm.o

execute_project_file.o: execute_project_file.cpp
	g++ -g -c -Wall -Wextra execute_project_file.cpp

Matrix.o: Matrix.h Matrix.cpp
	g++ -g -c -Wall -Wextra Matrix.cpp

DataBase.o: DataBase.h DataBase.cpp
	g++ -g -c -Wall -Wextra DataBase.cpp

RouteFinder.o: RouteFinder.h RouteFinder.cpp
	g++ -g -c -Wall -Wextra RouteFinder.cpp

Connection.o: Connection.h Connection.cpp
	g++ -g -c -Wall -Wextra Connection.cpp

DirectConnection.o: DirectConnection.h DirectConnection.cpp
	g++ -g -c -Wall -Wextra DirectConnection.cpp

City.o: City.h City.cpp
	g++ -g -c -Wall -Wextra City.cpp

run_tests: run_tests.o Tests.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o
	g++ -o tests.out run_tests.o Tests.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o

run_tests.o: run_tests.cpp
	g++ -g -c -Wall -Wextra run_tests.cpp

tests.o: Tests.cpp
	g++ -g -c -Wall -Wextra Tests.cpp

InterfaceTest: InterfaceTest.o Interface.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o
	g++ -o InterfaceTest.out InterfaceTest.o Interface.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o

Interface.o: Interface.cpp
	g++ -g -c -Wall -Wextra Interface.cpp

InterfaceTest.o: InterfaceTest.cpp
	g++ -g -c -Wall -Wextra InterfaceTest.cpp

clean:
	rm -f Interface.o InterfaceTest.o Interface.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o project_test.out tests.out Tests.o run_tests.o
