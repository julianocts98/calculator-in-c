# Calculator in C

This is a simple challenge made by [@MrTaiko314](https://github.com/MrTaiko314) for me and it aimed to serve as a little warming up before getting into the study of Data Structures and Algorithms.

The main idea was quite simple: to make the calculator work by parsing a single string expression that contains two natural numbers and one operator, instead of getting the user input for every number and operator.

I also decided to not use any other lib besides **stdio.h**, though this really made things harder as I may explain next.

## Problems caused by the constrained use of libraries

---

Since I couldn't use dynamic allocation with **malloc**, available at the **stdlib.h**, I was not able to return strings from the local scope of functions.
To bypass this case, I passed the strings I wanted to store the values as arguments for the functions and populated them inside the functions.

I also had a few problems since I couldn't simply copy string arrays easily through the use of **strcpy**. To bypass this, I used the same solution above for the dynamic allocation problem. I had to pass for each function the string I will store the value, and copy char by char of the string.

In the end, to be able to use a simple **switch** for solving the operation, I also couldn't simply convert the strings of the parsed expressions into numbers in an easy way, so I had to manually create functions for converting any string into integers.

## How to use

---

### Compiling using **GCC**:

1. Run `gcc -c main.c tests.c` to generate both `main.o` and `tests.o` files.
2. Compile them to an executable by running `gcc -o main.exe main.o tests.o`
3. Run `main.exe` passing either a string between parenthesis as an math expression.

### Compiling using **make**

1. Just run `make main` and it will compile everything needed and generate the `main.exe`.

### Using:

Run `main.exe` passing the arguments.

The following arguments are allowed:

- `"A O B"` -> a string where **A** and **B** are both natural numbers, and **O** is the operator.
  - The operators available are:
  - `+` -> add
  - `-` -> subtract
  - `*` -> multiply
  - `/` -> divide
- `-t` -> runs the test suite.

Examples:

- `main.exe "1+2"` should print the result `3`.
- `main.exe -t` should run the test suite.

## TODO

---

- [ ] Re-write the code using **stdlib.h** and **string.h** libraries.
- [ ] Accept negative numbers.
- [ ] Accept floating numbers.
- [ ] Accept multiple expressions as arguments, and solve them accordingly their priority.
