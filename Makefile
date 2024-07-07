# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -std=c99

# Include directories for Raylib (bedloha 3la hsab n path fain 3amlin raylib)
INCLUDES = -I/usr/local/include

# Library directories for Raylib
LIBS = -L/usr/local/lib -lraylib -lm

# Source files
SRC = main.c

# Output executable
TARGET = LesbianFlag2D

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(TARGET) $(LIBS)

# Clean target
clean:
	rm -f $(TARGET)
