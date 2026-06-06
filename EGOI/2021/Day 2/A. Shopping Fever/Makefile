# Compiler and flags
CXX = g++
FLAGS = -std=c++17 -O2 -Wall -Wextra -Wshadow -Wconversion -Wsign-conversion

# Source and output
SRC = main.cpp 
OUT = main

# Detect OS and switch compiler if Windows cross-compiling
ifeq ($(OS),Windows_NT)
    CXX = x86_64-w64-mingw32-g++
    OUT := $(OUT).exe
endif

# Default target
all: $(OUT)

# Build executable
$(OUT): $(SRC)
	$(CXX) $(FLAGS) $^ -o $@

# Clean
clean:
	rm -f $(OUT)
