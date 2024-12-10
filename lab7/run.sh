#!/bin/bash

# Create the Makefile each time
cat << 'EOF' > Makefile
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -I/usr/include/qt5 -I/usr/include/qt5/QtCore -fPIC

# Linker flags
LDFLAGS = -lQt5Core

# Target executable
TARGET = main

# Source files
SOURCES = main.cpp

# Build target without generating .o files
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

# Run the program
.PHONY: run
run: $(TARGET)
	./$(TARGET)

# Clean target
.PHONY: clean
clean:
	$(RM) $(TARGET)
EOF

# Build the target
make

# Run the program in the background
./main &

# Wait briefly and clean up
wait

# Clean up by removing both the executable and the Makefile
make clean
rm -f Makefile

# Exit the script automatically
exit 0