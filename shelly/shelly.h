

#ifndef SHELLY_H

#define SHELLY_H

// Declare constants
#define NUM_OF_COMMANDS 2

// Declare any function pointer types
typedef int (*Operation)(char *, int);

// Function prototypes
int check_command(int, char **);

int handle_reading(char *, int);

int handle_writing(char *, int);

int check_options(int);

#endif