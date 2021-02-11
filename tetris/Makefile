CC = gcc
TARGET = a.out
OBJS = controller.o model.o view.o keyboard.o
SRCS = controller.c model.c view.c keyboard.c
OPT = -Wall -pedantic
LIB = -lncurses

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(OPT) $(LIB)

run:
	./$(TARGET)

*.o: *.c
	$(CC) -c -o $@ $^

test: all run

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)

debug:
	$(CC) $(SRCS) -o $(TARGET) $(OPT) $(LIB)
