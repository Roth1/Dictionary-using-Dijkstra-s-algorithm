#Source-Files & Object-Files
SRCS = main.c functions.c list.c
OBJS = $(SRCS: .c = .o)

#Compiler & Flags
CC = gcc
CFLAGS = -Wall
LDFLAGS =

#Executable
EXEC = dict

##########################################

all : $(EXEC) move

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm  ./*.o

##########################################
