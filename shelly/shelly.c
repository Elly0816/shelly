#include <stdio.h>
#include "shelly.h"
#include <string.h>

/**
 *
 * TODO 1: Implement writing to a file
 *
 *
 *
 *
 *
 *
 */

/**
 *
 *
 */

int main(int argc, char **argv)
{
    char *commands[NUM_OF_COMMANDS] = {"read", "write"};
    Operation operation;

    if (check_command(argc, commands) != 0)
    {
        return -1;
    }

    // handle reading
    if (strcmp(argv[1], "read") == 0)
    {
        if (check_options(argc) != 0)
        {
            printf("Include a filename! \n");
            return -1;
        }
        printf("reading...");
    }

    // handle writing
    if (strcmp(argv[1], "write") == 0)
    {
        operation = handle_writing;
        // handle_writing(argv[2], argc);
    }
    operation(argv[2], argc);

    return 0;
}
