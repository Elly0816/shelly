#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define NUM_OF_COMMANDS 2

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

// Declare any function pointer types
typedef int (*Operation)(char *, int);

// Function prototypes
int check_command(int, char **);

int handle_reading(char *, int);

int handle_writing(char *, int);

int check_options(int);

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

    int should_run;

    do
    {
        should_run = 1;

        // handle reading
        if (strcmp(argv[1], "read") == 0)
        {
            if (check_options(argc) != 0)
            {
                printf("Include a filename! \n");
                return -1;
            }
            printf("reading...");
            should_run = 0;
        }

        // handle writing
        if (strcmp(argv[1], "write") == 0)
        {
            operation = handle_writing;
            // handle_writing(argv[2], argc);
            should_run = 0;
        }
        operation(argv[2], argc);

    } while (should_run);

    return 0;
}

int check_command(int no_of_commands, char **commands)
{

    if (no_of_commands < 2)
    {
        printf("You should enter some commands as well");
        printf("\n");
        printf("shelly <command> [options]");
        printf("\n");
        printf("The list of commands are:\n");
        for (int i = 0; i < NUM_OF_COMMANDS; i++)
        {
            printf("%d. %s\n", i + 1, commands[i]);
        }
        return -1;
    }

    return 0;
}

int handle_writing(char *filename, int count)
{
    if (check_options(count) != 0)
    {
        printf("Include a filename! \n");
        return -1;
    }

    FILE *fptr = fopen(filename, "w");
    printf("writing...\n");

    if (fptr == NULL)
    {
        perror("Issue opening file! ");
        printf("There was an error opening %s\n", filename);
        return -1;
    }

    printf("\nEnter the text you would like to write into the file below:\n");

    size_t buff_size = 10;
    char *buffer = (char *)malloc(buff_size * sizeof(char));
    size_t characters;

    while (1)
    {
        characters = strlen(fgets(buffer, buff_size - 1, stdin));

        if (characters == 1 && buffer[0] == '\n')
        { // Stops getting input when the user presses enter twice
            break;
        }

        fwrite(buffer, characters, 1, fptr);
    }

    free(buffer);
    buffer = NULL;
    fclose(fptr);
    fptr = NULL;
    printf("\nDone");
    return 0;
}

int check_options(int count)
{
    if (count < 3)
    {
        return -1;
    }

    return 0;
}