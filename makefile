DEPS=pieces.hpp board.hpp position.hpp
CC=clang++
CFLAGS= 

chess: board.o position.o main.o pieces.o
	$(CC) -o chess pieces.o board.o position.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm *.o chess