#!/bin/bash

# Create a static library called liball.a from all .c files in the current directory
gcc -Wall -pedantic -Werror -Wextra -c *.c
ar -rc liball.a *.o
ranlib liball.a
