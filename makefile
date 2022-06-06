RouteFinderApplication: RouteFinderApplication.o Interface.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o
	g++ -o RouteFinderApplication.out RouteFinderApplication.o Interface.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o

run_tests: run_tests.o Tests.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o
	g++ -o tests.out run_tests.o Tests.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o

RouteFinderApplication.o: RouteFinderApplication.cpp
	g++ -g -c RouteFinderApplication.cpp

run_tests.o: run_tests.cpp
	g++ -g -c run_tests.cpp

DirectConnection.o: DirectConnection.h DirectConnection.cpp
	g++ -g -c DirectConnection.cpp

Connection.o: Connection.h Connection.cpp
	g++ -g -c Connection.cpp

Matrix.o: Matrix.h Matrix.cpp
	g++ -g -c Matrix.cpp

DataBase.o: DataBase.h DataBase.cpp
	g++ -g -c DataBase.cpp

FinderAlgorithm.o: FinderAlgorithm.h FinderAlgorithm.cpp
	g++ -g -c FinderAlgorithm.cpp

RouteFinder.o: RouteFinder.h RouteFinder.cpp
	g++ -g -c RouteFinder.cpp

Interface.o: Interface.cpp
	g++ -g -c Interface.cpp

tests.o: Tests.cpp
	g++ -g -c Tests.cpp	

clean:
	rm -f *.o *.out
