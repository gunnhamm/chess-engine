DEPS=pieces.hpp board.hpp position.hpp
CC=g++
CXXFLAGS=-g 

chess: board.o position.o main.o pieces.o
	$(CC) -o chess pieces.o board.o position.o main.o $(CFLAGS) 

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm *.o chess