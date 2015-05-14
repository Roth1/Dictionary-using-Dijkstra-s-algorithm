#Source-Files & Object-Files
SRCS = main.c functions.c liste.c
OBJS = $(SRCS: .c = .o)
DEPS = functions.h liste.h

#Compiler & Flags
CC = gcc
CFLAGS = -I. -Wall -Werror
LDFLAGS = -lm
DEPS = liste.h functions.h

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
