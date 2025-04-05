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
    char *commands[NUM_OF_COMMANDS] = {"read", "write", "size"};
    Operation operation = NULL;

    if (check_command(argc, commands) != 0)
    {
        return -1;
    }

    // handle reading text
    if (strcmp(argv[1], "read") == 0)
    {
        operation = handle_reading;
    }

    // handle writing text
    if (strcmp(argv[1], "write") == 0)
    {
        operation = handle_writing;
        // handle_writing(argv[2], argc);
    }

    // count the number of characters in the file effectively returning the size of the file
    if (strcmp(argv[1], "size") == 0)
    {
        get_size(argv[2], argc);
    }
    if (operation)
    {

        operation(argv[2], argc);
    }

    return 0;
}
