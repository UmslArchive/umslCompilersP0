##############################################################################
#Author:	Colby Ackerman                                                   #
#Class:		Program Translations (CS4280)                                    #
#Assign:	Project 0                                                        #
#Date:		September 22, 2019                                               #
##############################################################################

CC = g++
CFLAGS = -I . -g
TARGET =p0
OBJS = main.o BinarySearchTree.o Arguments.o Application.o
.SUFFIXES: .cpp .o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o $(TARGET) *.tree *.inorder *.postorder *.preorder