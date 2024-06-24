CC = gcc
CFLAGS = -Wall -c -g
LDFLAGS = -o

INC = ./inc/
SRC = ./src
OBJ = ./obj
BIN = ./bin

IFLAGS = -I $(INC)

# List all source files for myFunction
MYFUNCTION_SRCS = CB.c  OP.c dataprocess.c login.c signup.c
MYFUNCTION_OBJS = $(patsubst %.c, $(OBJ)/%.o, $(MYFUNCTION_SRCS))

all: client CDR

CDR: $(OBJ)/server.o $(MYFUNCTION_OBJS)
	$(CC) $(LDFLAGS) $(BIN)/CDR $(OBJ)/server.o $(MYFUNCTION_OBJS) -pthread

$(OBJ)/server.o: $(SRC)/server.c
	$(CC) $(CFLAGS) $(SRC)/server.c -pthread $(IFLAGS)
	mv *.o $(OBJ)/

# Compile each source file in myFunction directory separately
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $< -o $@ $(IFLAGS)

client: $(OBJ)/client.o
	$(CC) $(LDFLAGS) $(BIN)/client $(OBJ)/client.o

$(OBJ)/client.o: $(SRC)/client.c
	$(CC) $(CFLAGS) $(SRC)/client.c
	mv *.o $(OBJ)/

clean:
	rm -f $(OBJ)/*
	rm -f $(BIN)/*
	@echo "Cleaning Done!"

