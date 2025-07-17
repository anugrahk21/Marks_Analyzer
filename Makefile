# Makefile for GPA Analyzer
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# Target executable
TARGET = gpa_analyzer

# Source files
SOURCES = gpa_analyzer.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	del /f $(OBJECTS) $(TARGET).exe

# Run the program
run: $(TARGET)
	./$(TARGET)

# Help target
help:
	@echo Available targets:
	@echo   all     - Build the program
	@echo   clean   - Remove build artifacts
	@echo   run     - Build and run the program
	@echo   help    - Show this help message

.PHONY: all clean run help
