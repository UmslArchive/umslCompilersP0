CC = g++
CFLAGS = -I . -g
TARGET =p0
OBJS = main.o BST.o FileManager.o
.SUFFIXES: .cpp .o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
