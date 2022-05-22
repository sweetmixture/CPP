CC=g++ -std=c++17

parser.x : main.o ReadWrite_Parser.o
	$(CC) -o parser.x $^

main.o : main.cpp
	$(CC) -c $<

ReadWrite_Parser.o : ReadWrite_Parser.cpp ReadWrite_Parser.h
	$(CC) -c $<
