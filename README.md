# STV Compiler

A modern compiler for the STV programming language, designed with performance and extensibility in mind.

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Building from Source](#building-from-source)
  - [Running the Compiler](#running-the-compiler)
- [Testing](#testing)
- [Development](#development)
  - [Build Options](#build-options)
  - [Commit Conventions](#commit-conventions)
- [Documentation](#documentation)
- [License](#license)

## Overview

The STV Compiler project implements a complete compiler for the STV language, transforming STV source code into executable binaries. The compiler is built with a modular architecture, separating lexical analysis, parsing, semantic analysis, and code generation into distinct components.

## Features

- Full implementation of the STV language specification
- Modular compiler architecture
- Robust error detection and reporting
- Optimized code generation
- Comprehensive test suite
- Cross-platform support

## Project Structure

```bash
stvcompiler/
├── include/         # Header files
│   ├── lexer.h      # Lexical analysis
│   ├── parser.h     # Parsing
│   ├── semantic.h   # Semantic analysis
│   └── codegen.h    # Code generation
├── src/             # Source code
│   ├── lexer.cpp    # Lexical analyzer implementation
│   ├── parser.cpp   # Parser implementation
│   ├── semantic.cpp # Semantic analyzer implementation
│   ├── codegen.cpp  # Code generator implementation
│   ├── main.cpp     # Main compiler driver
│   └── utils.h      # Utility functions
├── tests/           # Test files
│   └── test.stv     # Test cases
├── docs/            # Documentation
│   ├── design.md              # Design decisions
│   ├── Compiler_Roadmap.md    # Development roadmap
│   └── commit_conventions.md  # Commit message format
├── build/           # Build artifacts (generated)
├── bin/             # Compiled binaries (generated)
├── Makefile         # Build system
├── .gitignore       # Git ignore rules
├── LICENSE          # License information
└── README.md        # This file
```

## Getting Started

### Prerequisites

- C++17 compatible compiler (GCC 8+, Clang 7+, or MSVC 19.14+)
- Make build system

### Building from Source

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/stvcompiler.git
   cd stvcompiler
   ```

2. Build the compiler:

   ```bash
   make
   ```

This will create the compiler executable at `bin/stvcompiler`.

### Running the Compiler

To compile an STV source file:

```bash
make run file=path/to/your/file.stv
```

Or directly:

```bash
./bin/stvcompiler path/to/your/file.stv
```

## Testing

The project includes a test suite to verify the compiler's functionality. To run all tests:

```bash
make test
```

## Development

### Build Options

The Makefile provides several useful targets:

- `make all` - Build the compiler (default)
- `make test` - Run the test suite
- `make run file=path/to/file.stv` - Compile a specific file
- `make clean` - Remove build artifacts
- `make rebuild` - Clean and rebuild the project
- `make debug` - Build with debugging symbols
- `make release` - Build with optimizations
- `make help` - Display available commands

### Commit Conventions

This project follows conventional commit guidelines. See [commit_conventions.md](docs/commit_conventions.md) for details.

Example commit message:

```bash
feat: add support for array literals in parser
```

## Documentation

- [Design Documentation](docs/design.md) - Architectural decisions and language design
- [Compiler Roadmap](docs/Compiler_Roadmap.md) - Development plan and milestones

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
