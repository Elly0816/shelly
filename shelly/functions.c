#include "shelly.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

// Function definitions

int check_command(int no_of_commands, Command *commands)
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
            printf("%d. %s: %s\n", i + 1, commands[i].name, commands[i].description);
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

void clear_buffer(void)
{
    while (getchar() != '\n')
        ;
}

void get_name(Student *student)
{
    int invalid;

    // printf("Enter the name of the student: ");

    do
    {
        invalid = 0;
        if (scanf("%[^\n]", student->name) != 1)
        {
            printf("Enter a valid name! ");
            clear_buffer();
            invalid = 1;
        }
        else if (strlen(student->name) > 29)
        {
            printf("Your name is too long! ");
            clear_buffer();
            invalid = 1;
        }
        else if (strlen(student->name) == 0)
        {
            printf("Name cannot be empty! ");
            clear_buffer();
            invalid = 1;
        }
        else
        {
            for (int i = 0; i < strlen(student->name); i++)
            {
                if (!isalpha(student->name[i]) && !isspace(student->name[i]))
                {
                    printf("Your name shoud only include letters! ");
                    clear_buffer();
                    invalid = 1;
                }
            }
        }
    } while (invalid);

    // strcpy(student->name, temp_name);
    clear_buffer();
}

void get_age(Student *student)
{
    printf("Enter %s's age: ", student->name);

    int invalid;

    do
    {
        invalid = 0;

        if (scanf("%d", &student->age) != 1)
        {
            printf("Enter a valid number! ");
            clear_buffer();
            invalid = 1;
        }
        else if (student->age < 1)
        {
            printf("You cannot be less than a year old! ");
            clear_buffer();
            invalid = 1;
        }
    } while (invalid);
    clear_buffer();
}

void get_email(Student *student)
{

    printf("Enter %s's email: ", student->name);
    int invalid;
    do
    {
        scanf("%s", student->email);

        if (strlen(student->email) > 49)
        {
            printf("Your email is too long! ");
            clear_buffer();
            invalid = 1;
        }
        else if (strlen(student->email) == 0)
        {
            printf("You cannot leave email empty! ");
            clear_buffer();
            invalid = 1;
        }
        else if (strcspn(student->email, "@") == strlen(student->email) || strcspn(student->email, ".") == strlen(student->email))
        {
            printf("Enter a valid email! ");
            clear_buffer();
            invalid = 1;
        }

    } while (invalid);
    clear_buffer();
}

void get_gpa(Student *student)
{
    printf("Enter %s's gpa: ", student->name);

    int invalid;

    do
    {
        invalid = 0;
        if (scanf("%f", &student->gpa) != 1)
        {
            printf("Enter a number! ");
            clear_buffer();
            invalid = 1;
        }
        else if (student->gpa <= 0 || student->gpa > 5)
        {
            printf("Your gpa cannot be less than or equal to zero, and it cannot be more than 5!: ");
            clear_buffer();
            invalid = 1;
        }
    } while (invalid);
    clear_buffer();
}

void get_course(Student *student)
{

    char courses[6][30] = {"Software Engineering", "UI/UX", "Machine Learning and A.I.",
                           "Web Design", "Data Analysis", "Graphics Design and Multimedia"};

    printf("\n---- Here are the available courses ----\n");
    for (int i = 0; i < 6; i++)
    {
        printf("Press %d to pick %s\n", i + 1, courses[i]);
    }

    int invalid;
    int user_choice;
    do
    {
        invalid = 0;
        if (scanf("%d", &user_choice) != 1 || (user_choice < 1 || user_choice > 6))
        {
            invalid = 1;
            clear_buffer();
            printf("Enter a valid number (1-6) ");
        }
    } while (invalid);
    clear_buffer();
    strcpy(student->course, courses[user_choice - 1]);
}

void write_student(char *mode)
{

    printf("How many students would you like to add? ");
    int number_of_students = 0;
    int invalid;

    do
    {
        invalid = 0;
        if (scanf("%d", &number_of_students) != 1 || number_of_students < 1)
        {
            printf("Please Enter a positive number! ");
            clear_buffer();
            invalid = 1;
        }

    } while (invalid);
    clear_buffer();

    printf("\nThe number of students is %d\n\n", number_of_students);
    Student *students = (Student *)malloc(number_of_students * sizeof(Student));

    if (students == NULL)
    {
        printf("Error allocating memory!\n");
        return;
    }
    for (int i = 0; i < number_of_students; i++)
    {
        printf("Enter name for student %d ", i + 1);
        get_name(&students[i]);
        get_age(&students[i]);
        get_email(&students[i]);
        get_gpa(&students[i]);
        get_course(&students[i]);
    }

    printf("\n\n---------- Entered Students ----------\n\n");
    for (int i = 0; i < number_of_students; i++)
    {
        printf("Student %d's name is %s\n", i + 1, students[i].name);
    }
    // write the students to a file
    FILE *fptr;

    if (mode != NULL && strcmp(mode, "-a") == 0)
    {
        fptr = fopen(STUDENT_FILE, "ab");
    }
    else
    {
        fptr = fopen(STUDENT_FILE, "wb");
    }

    if (fptr == NULL)
    {
        printf("There was an error opening the file!\n");
        return;
    }
    size_t number_of_students_written = fwrite(students, sizeof(Student), number_of_students, fptr);

    if (number_of_students_written != number_of_students)
    {
        printf("There was an error writing the students!\n");
        fclose(fptr);
        fptr = NULL;
        free(students);
        students = NULL;
        return;
    }

    fclose(fptr);
    fptr = NULL;
    free(students);
    students = NULL;

    printf("Successfully written %d students to the students to the file\n", number_of_students);
    return;
}

void read_students(void)
{
    FILE *fptr = fopen(STUDENT_FILE, "rb");

    if (fptr == NULL)
    {
        printf("There was an error opening the file");
        return;
    }

    // Get the file size to calculate the number of students in the file
    fseek(fptr, 0, SEEK_END);
    size_t file_size = ftell(fptr);
    int number_of_students = file_size / sizeof(Student);
    rewind(fptr);

    Student *students = (Student *)malloc(number_of_students * sizeof(Student));

    if (students == NULL)
    {
        printf("There was an error allocating memory for the students!\n");
        return;
    }

    size_t students_read = fread(students, sizeof(Student), number_of_students, fptr);

    if (students_read != number_of_students)
    {
        printf("Could not read the entire file properly! \n");
        fclose(fptr);
        fptr = NULL;
        free(students);
        students = NULL;
        return;
    }

    printf("\n----Here are the students that were read successfully----\n\n");

    for (int i = 0; i < number_of_students; i++)
    {
        printf("Student %d: \nNAME = %s, \nAGE = %d, \nEMAIL = %s, \nGPA = %.2f, \nCOURSE = %s\n\n", i + 1, students[i].name, students[i].age, students[i].email, students[i].gpa, students[i].course);
    }

    fclose(fptr);
    fptr = NULL;
    free(students);
    students = NULL;
    return;
}