Employee.o:Employee.h Employee.cpp
	g++ -c Employee.cpp

main.o:main.cpp Employee.h
	g++ -c main.cpp
	
main: main.o Employee.o
	g++ -pedantic-errors -std=c++11 Employee.o main.o -o main
