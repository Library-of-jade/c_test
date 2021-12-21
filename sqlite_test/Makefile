CC = gcc
GFLAGS = -o
OBJS = main.o sqlite3.o
TARGET = test

$(TARGET): $(OBJS)
	$(CC) $(GFLAGS) $(TARGET) $(OBJS)

main.o : main.c sqlite3.h
	$(CC) -c main.c

sqlite3.o : sqlite3.c sqlite3.h
	$(CC) -c sqlite3.c