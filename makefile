execute_test: City.o Connection.o DirectConnection.o Matrix.o DataBase.o execute_project_file.o RouteFinder.o
	g++ -g -o project_test.out City.o Connection.o DirectConnection.o Matrix.o DataBase.o execute_project_file.o RouteFinder.o

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


City.o: City.h City.cpp
	g++ -g -c City.cpp


clean:
	rm -f City.o Connection.o DirectConnection.o Matrix.o DataBase.o project_test.out execute_project_file.o RouteFinder.o