execute_test: Connection.o DirectConnection.o Matrix.o DataBase.o execute_project_file.o RouteFinder.o FinderAlgorithm.o
	g++ -o project_test.exe Connection.o DirectConnection.o Matrix.o DataBase.o execute_project_file.o RouteFinder.o FinderAlgorithm.o

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

<<<<<<< HEAD
City.o: City.h City.cpp
	g++ -g -c -pedantic -Wall -Wextra City.cpp
=======
FinderAlgorithm.o: FinderAlgorithm.h FinderAlgorithm.cpp
	g++ -c FinderAlgorithm.cpp
>>>>>>> 870be7dcd27fc78f9b0ed515ade38ef71863d9cc

run_tests: run_tests.o Tests.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o
	g++ -o tests.exe run_tests.o Tests.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o

<<<<<<< HEAD
file_test.o: file_test.cpp
	g++ -c -pedantic -Wall -Wextra file_test.cpp
=======
run_tests.o: run_tests.cpp
	g++ -g -c run_tests.cpp
>>>>>>> 870be7dcd27fc78f9b0ed515ade38ef71863d9cc

tests.o: Tests.cpp
	g++ -g -c Tests.cpp

<<<<<<< HEAD
FinderAlgorithm.o: FinderAlgorithm.h FinderAlgorithm.cpp
	g++ -c -pedantic -Wall -Wextra FinderAlgorithm.cpp

FinderAlgorithm_test.o: FinderAlgorithm_test.cpp
	g++ -c -pedantic -Wall -Wextra FinderAlgorithm_test.cpp
=======
InterfaceTest: InterfaceTest.o Interface.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o
	g++ -o InterfaceTest.exe InterfaceTest.o Interface.o Connection.o DirectConnection.o Matrix.o DataBase.o RouteFinder.o FinderAlgorithm.o

Interface.o: Interface.cpp
	g++ -g -c Interface.cpp

InterfaceTest.o: InterfaceTest.cpp
	g++ -g -c InterfaceTest.cpp
>>>>>>> 870be7dcd27fc78f9b0ed515ade38ef71863d9cc

clean:
	del *.o *.exe
