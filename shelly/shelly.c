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
    Command commands[NUM_OF_COMMANDS] = {{"read", "Read from a file - must include the filename"},
                                         {"write", "Write from a file - must include filename"},
                                         {"size", "Returns the size of a file in bytes - must include filename"},
                                         {"bwrite", "Write to a binary file. Add the '-a' flag to append to the file"},
                                         {"bread", "Read from a binary file."}};
    Text_File_Ops text_op = NULL;

    if (check_command(argc, commands) != 0)
    {
        return -1;
    }

    // handle reading text
    if (strcmp(argv[1], "read") == 0)
    {
        text_op = handle_reading;
    }

    // handle writing text
    if (strcmp(argv[1], "write") == 0)
    {
        text_op = handle_writing;
        // handle_writing(argv[2], argc);
    }

    // count the number of characters in the file effectively returning the size of the file
    if (strcmp(argv[1], "size") == 0)
    {
        get_size(argv[2], argc);
    }

    // Handle writing binary to a file
    if (strcmp(argv[1], "bwrite") == 0)
    {
        // User gets the option of writing into a student.bin file

        // Flag should mark whether to write or append to the file
        if (argc > 2)
        {
            if (strcmp(argv[2], "-a") == 0)
            {
                // Append to binary file
                write_student("-a");
            }
            else
            {
                printf("Did you mean to write '-a'?");
            }
        }
        else
        {
            // Overwrite binary file
            write_student(NULL);
        }
    }

    if (strcmp(argv[1], "bread") == 0)
    {
        if (argc > 2)
        {
            for (int i = 2; i < argc; i++)
            {
                printf("Unknown argument '%s'\n", argv[i]);
            }
        }
        else
        {

            read_students();
        }
    }

    // handle operations
    if (text_op)
    {

        text_op(argv[2], argc);
    }

    return 0;
}
