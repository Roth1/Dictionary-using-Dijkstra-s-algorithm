#Source-Files & Object-Files
SRCS = main.c fonctions.c sommet.c
OBJS = $(SRCS: .c = .o)
DEPS = fonctions.h sommet.h

#Compiler & Flags
CC = gcc
CFLAGS = -I. -Wall -Werror
LDFLAGS = -lm

#Executable
EXEC = dict

##########################################

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm  ./*.o

##########################################
