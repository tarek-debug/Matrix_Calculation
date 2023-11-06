# Matrix Multiplication

## Overview
This repository contains two C programs that read in two 3x3 integer matrices from files, calculate their product, and save the resulting matrix to a new file. The program `program1.c` uses a more direct approach with standard array indexing, while `program2.c` employs pointers to achieve the same functionality.

## Author
Tarek Solamy

## Version
- `program1.c`: Version 1.0 dated 10/06/2022
- `program2.c`: Version 1.0 dated 10/19/2022

## Files
- `program1.c`: Program that reads, multiplies, and writes matrices using array indexing.
- `program2.c`: Program that performs similar operations using pointer arithmetic.

## Input Files
- `p3_a.in`: Contains the first 3x3 integer matrix.
- `p3_b.in`: Contains the second 3x3 integer matrix.

## Output File
- `p3.res`: Contains the resulting 3x3 matrix after multiplication.

## Build Instructions
To compile the programs, you can use the `gcc` compiler. Here's how you can compile each program:

For `program1.c`:
gcc -o program1 program1.c
For `program2.c`:
gcc -o program2 program2.c


## Execution
After building the program, you can run it using:

For `program1`:
./program1

For `program2`:
./program2


Make sure the input files `p3_a.in` and `p3_b.in` are in the same directory as the executable.

## Contributing
Please feel free to fork this repository and contribute by making a pull request. All contributions are welcome.

## License
This project is open-sourced under the MIT License. See the LICENSE file for details.






