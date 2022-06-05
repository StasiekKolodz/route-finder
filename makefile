execute_test: Connection.o DirectConnection.o Matrix.o DataBase.o execute_project_file.o RouteFinder.o FinderAlgorithm.o
	g++ -o project_test.out Connection.o DirectConnection.o Matrix.o DataBase.o execute_project_file.o RouteFinder.o FinderAlgorithm.o

execute_project_file.o: execute_project_file.cpp
	g++ -g -c execute_project_file.cpp

Matrix.o: Matrix.h Matrix.cpp
	g++ -g -c Matrix.cpp

DataBase.o: DataBase.h DataBase.cpp
	g++ -g -c DataBase.cpp

RouteFinder.o: RouteFinder.h RouteFinder.cpp
	g++ -g -c RouteFinder.cpp

Connection.o: Connection.h Connection.cpp
	g++ -g -c Connection.cpp

DirectConnection.o: DirectConnection.h DirectConnection.cpp
	g++ -g -c DirectConnection.cpp

FinderAlgorithm.o: FinderAlgorithm.h FinderAlgorithm.cpp
	g++ -c FinderAlgorithm.cpp

run_tests: run_tests.o Tests.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o
	g++ -o tests.out run_tests.o Tests.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o

run_tests.o: run_tests.cpp
	g++ -g -c run_tests.cpp

tests.o: Tests.cpp
	g++ -g -c Tests.cpp

clean:
	rm -f *.o *.out
