execute_test: City.o Connection.o DirectConnection.o Matrix.o DataBase.o execute_project_file.o RouteFinder.o
	g++ -o project_test.out City.o Connection.o DirectConnection.o Matrix.o DataBase.o execute_project_file.o RouteFinder.o

execute_project_file.o: execute_project_file.cpp
	g++ -c execute_project_file.cpp

Matrix.o: Matrix.h Matrix.cpp
	g++ -c Matrix.cpp

RouteFinder.o: RouteFinder.h RouteFinder.cpp
	g++ -c RouteFinder.cpp

Connection.o: Connection.h Connection.cpp

DirectConnection.o: DirectConnection.h DirectConnection.cpp
	g++ -c DirectConnection.cpp

City.o: City.h City.cpp
	g++ -c City.cpp

file_test: file_test.o
	g++ -o file_test.out file_test.o

file_test.o: file_test.cpp
	g++ -c file_test.cpp


clean:
	rm -f City.o Connection.o DirectConnection.o Matrix.o DataBase.o project_test.out execute_project_file.o RouteFinder.o