execute_test: City.o Connection.o DirectConnection.o Matrix.o DataBase.o execute_project_file.o RouteFinder.o FinderAlgorithm.o
	g++ -o project_test.out City.o Connection.o DirectConnection.o Matrix.o DataBase.o execute_project_file.o RouteFinder.o FinderAlgorithm.o

execute_project_file.o: execute_project_file.cpp
	g++ -g -c -pedantic -Wall -Wextra execute_project_file.cpp

Matrix.o: Matrix.h Matrix.cpp
	g++ -g -c -pedantic -Wall -Wextra Matrix.cpp

DataBase.o: DataBase.h DataBase.cpp
	g++ -g -c -pedantic -Wall -Wextra DataBase.cpp

RouteFinder.o: RouteFinder.h RouteFinder.cpp
	g++ -g -c -pedantic -Wall -Wextra RouteFinder.cpp

Connection.o: Connection.h Connection.cpp
	g++ -g -c -pedantic -Wall -Wextra Connection.cpp

DirectConnection.o: DirectConnection.h DirectConnection.cpp
	g++ -g -c -pedantic -Wall -Wextra DirectConnection.cpp

City.o: City.h City.cpp
	g++ -g -c -pedantic -Wall -Wextra City.cpp

file_test: file_test.o
	g++ -o file_test.exe file_test.o

file_test.o: file_test.cpp
	g++ -c -pedantic -Wall -Wextra file_test.cpp

FinderAlgorithm_test: FinderAlgorithm_test.o City.o Connection.o DirectConnection.o Matrix.o DataBase.o FinderAlgorithm.o RouteFinder.o
	g++ -o FinderAlgorithm_test.out FinderAlgorithm_test.o City.o Connection.o DirectConnection.o Matrix.o DataBase.o FinderAlgorithm.o RouteFinder.o

FinderAlgorithm.o: FinderAlgorithm.h FinderAlgorithm.cpp
	g++ -c -pedantic -Wall -Wextra FinderAlgorithm.cpp

FinderAlgorithm_test.o: FinderAlgorithm_test.cpp
	g++ -c -pedantic -Wall -Wextra FinderAlgorithm_test.cpp

clean:
	rm -f City.o Connection.o DirectConnection.o Matrix.o DataBase.o project_test.out execute_project_file.o RouteFinder.o file_test.o file_test.out FinderAlgorithm.o FinderAlgorithm_test.o FinderAlgorithm_test.out
