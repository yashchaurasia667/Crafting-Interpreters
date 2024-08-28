# compiler to use
CC = gcc

# compiler flags
CFLAGS = -Wall -g

# the target executable
TARGET = dll

# the first target is the one that gets executed when u run 'make'
all: $(TARGET)

# the executable depends on the hello.o object file
$(TARGET): dll.o
	$(CC) $(CFLAGS) -o $(TARGET) dll.o
	./$(TARGET)

# compile hello.c to hello.o
dll.o: dll.c
	$(CC) $(CFLAGS) -c dll.c

# cleanup by removing object files and the executable
clean:
	rm -f *.o $(TARGET)