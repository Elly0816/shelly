#include <stddef.h>

#ifndef SHELLY_H

#define SHELLY_H

// Declare constants
#define NUM_OF_COMMANDS 5

#define STUDENT_FILE "students.bin"

// Declare any function pointer types
typedef int (*Text_File_Ops)(char *, int);

// Define any structures
typedef struct Command
{
    char *name;
    char *description;
} Command;

typedef struct Student
{
    char name[30];
    int age;
    char email[50];
    float gpa;
    char course[30];
} Student;
// Function prototypes
int check_command(int, Command *);

int handle_reading(char *, int);

int handle_writing(char *, int);

int check_options(int);

size_t get_size(char *, int);

void get_name(Student *);

void get_age(Student *);

void get_email(Student *);

void get_gpa(Student *);

void get_course(Student *);

void write_student(char *);

void clear_buffer(void);

void read_students(void);

#endif