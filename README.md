# NanoTekSpice

## Overview

**NanoTekSpice** is a digital logic simulator built in **C++**^^. **It constructs a graph of simulated digital electronic components (chipsets) based on a configuration file and simulates their behavior using boolean logic**^^. **Unlike pure boolean algebra, this simulator incorporates a ****tristate logic** system, accounting for `<span class="citation-47">true</span>`, `<span class="citation-47">false</span>`, and `<span class="citation-47">undefined</span>` states^^.

**The project simulates various components ranging from simple elementary gates (AND, OR, NOT) to complex chipsets like the 4008 4-bit adder or the 4514 4-bit decoder**.

---

## Features

* **Tristate Logic:** Handles `<span class="citation-45">0</span>` (false), `<span class="citation-45">1</span>` (true), and `<span class="citation-45">U</span>` (undefined) values.
* **Component Factory:** Implements a generic component creation system using a factory pattern.
* **Interactive Shell:** Includes a command-line interface to manipulate input values, simulate clock ticks, and display the state of the circuit.
* **Modular Architecture:** All components inherit from the `<span class="citation-42">nts::IComponent</span>` interface, ensuring high extensibility.

---

## Getting Started

### Prerequisites

* **A C++ compiler (supporting C++ standards used in the project)**^^.
* **Make** or **CMake** for the build process^^.

### Compilation

To compile the project using the provided  **Makefile** , run the following commands in your terminal:

**Bash**

```
# To compile the nanotekspice binary
make

# To remove object files
make clean

# To remove object files and the binary
make fclean

# To re-compile the entire project
make re
```

---

## Usage

Run the simulator by passing a circuit configuration file (`.nts`) as an argument:

**Bash**

```
./nanotekspice [circuit_file.nts]
```

### Available Commands

Once the program is running, you can use the following commands in the interactive prompt:

* **`<span class="citation-37">display</span>`** **: Prints the current tick and the values of all inputs and outputs**.
* **`<span class="citation-36">simulate</span>`** **: Simulates one tick of the circuit**.
* **`<span class="citation-35">loop</span>`** **: Continuously runs the simulation until a **`<span class="citation-35">SIGINT</span>` (CTRL+C) is received^^.
* **`<span class="citation-34">[input_name]=[value]</span>`** **: Changes the value of an input (values: **`<span class="citation-34">0</span>`, `<span class="citation-34">1</span>`, or `<span class="citation-34">u</span>`).
* **`<span class="citation-33">exit</span>`** **: Closes the program**.
* **CTRL+D** **: Stops the program with status 0**.

---

## Configuration File Format

The `.nts` files are divided into two main sections:

1. **`<span class="citation-31">.chipsets</span>`** **: Declares and names the components used in the circuit**.
2. **`<span class="citation-30">.links</span>`** **: Defines the bidirectional links between specific pins of the components**.

**Example:**

**Plaintext**

```
.chipsets:
input a
input b
4071 my_or_gate
output s

.links:
a:1 my_or_gate:1
b:1 my_or_gate:2
my_or_gate:3 s:1
```

---

## Documentation (Doxygen)

This project contains brief Doxygen comments added above function definitions in `src/` to help generate API documentation.

To generate documentation (if you have Doxygen installed):

```bash
doxygen Doxyfile
```

If no `Doxyfile` is present you can create a minimal one with:

```bash
doxygen -g Doxyfile
```

Then edit `Doxyfile` (set `PROJECT_NAME`, `INPUT = src include`, and `RECURSIVE = YES`) and run `doxygen Doxyfile`.
