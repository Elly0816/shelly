#include "shelly.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

// Function definitions

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
        printf("Not enough arguments for operation!\n");
        return -1;
    }

    printf("Continuing with operation\n");
    return 0;
}

int handle_reading(char *filename, int count)
{

    if (check_options(count) != 0)
    {
        printf("Include a filename! \n");
        return -1;
    }

    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        perror("Could not open file");
        printf("Make sure the file %s exists\n", filename);
        return -1;
    }

    size_t number_of_chars = 100;
    char *buffer = (char *)malloc(number_of_chars * sizeof(char));

    if (buffer == NULL)
    {
        printf("There was an error creating the buffer!\n");
        return -1;
    }

    printf("Reading...\n");
    while (fgets(buffer, number_of_chars, fptr))
    {
        printf("%s", buffer);
    }

    printf("\nDone");
    free(buffer);
    buffer = NULL;
    fclose(fptr);
    fptr = NULL;
    return 0;
}

size_t get_size(char *filename, int count)
{

    if (check_options(count) != 0)
    {
        printf("Include a filename! \n");
        return 0;
    }

    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("There was an error opening the file\n");
        return 0;
    }

    size_t position;

    if (fseek(fptr, 0, SEEK_END) != 0)
    {
        printf("There was en error seeking through the file\n");
        return 0;
    }

    position = ftell(fptr);

    printf("The size of %s is %zu bytes\n", filename, position);

    fclose(fptr);
    fptr = NULL;
    return position;
}