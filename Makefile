# Makefile for STV Compiler
# ===========================================

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic -I./include

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include
TEST_DIR = tests

# Files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
EXECUTABLE = $(BIN_DIR)/stvcompiler

# Default target
all: setup $(EXECUTABLE)

# Setup build directories
setup:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)

# Build the compiler
$(EXECUTABLE): $(OBJECTS)
	@echo "Linking..."
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build successful: $(EXECUTABLE)"

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

# Run tests
test: $(EXECUTABLE)
	@echo "Running tests..."
	@$(EXECUTABLE) $(TEST_DIR)/test.stv
	@echo "Tests completed."

# Run the compiler with a specific input file
run: $(EXECUTABLE)
	@echo "Running compiler..."
	@$(EXECUTABLE) $(file)

# Clean build files
clean:
	@echo "Cleaning build files..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "Clean completed."

# Rebuild the project
rebuild: clean all

# Help command
help:
	@echo "STV Compiler Makefile"
	@echo "---------------------"
	@echo "Targets:"
	@echo "  all      - Build the compiler (default)"
	@echo "  test     - Run tests"
	@echo "  run      - Run the compiler (usage: make run file=path/to/file.stv)"
	@echo "  clean    - Remove build files"
	@echo "  rebuild  - Clean and rebuild"
	@echo "  help     - Display this help message"

# Debug build
debug: CXXFLAGS += -g -O0 -DDEBUG
debug: rebuild

# Release build
release: CXXFLAGS += -O3 -DNDEBUG
release: rebuild

# Phony targets
.PHONY: all setup test run clean rebuild help debug release
