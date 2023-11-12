# Makefile for raudio_sdl example

# Compiler settings
CC = gcc
CFLAGS = -Wall -std=c99 -DRAUDIO_STANDALONE -DSUPPORT_MODULE_RAUDIO -DSUPPORT_FILEFORMAT_WAV -DSUPPORT_FILEFORMAT_XM

# Include directories
INCLUDES = -I../src -I../src/external

# Libraries
LIBS = -L. -lsdl2 -lsetupapi -lole32 -lgdi32 -limm32 -lversion -loleaut32 -lwinmm

# Source files
SRC = raudio_sdl.c ../src/raudio.c

# Output binary
BIN = raudio_sdl.exe

# Default target
all: $(BIN)

$(BIN): $(SRC)
	$(CC) -o $(BIN) $(SRC) $(CFLAGS) $(INCLUDES) $(LIBS)

# Clean target to remove the compiled binary
clean:
	rm -f $(BIN)

# Phony targets
.PHONY: all clean
