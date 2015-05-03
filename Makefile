#Source-Files & Object-Files
SRCS = main.c functions.c list.c
OBJS = $(SRCS: .c = .o)

#Compiler & Flags
CC = gcc
CFLAGS = -Wall
LFLAGS =

#Executable
EXEC = dict

##########################################

all : $(EXEC) move

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm  ./*.o

##########################################
