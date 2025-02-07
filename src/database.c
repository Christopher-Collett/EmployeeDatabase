#include <stdio.h>

#include "database.h"

int create_database(char *file_path)
{
    printf("Created new database at: %s\n", file_path);
    return 0;
}

int add_employee(char *file_path, char *employee)
{
    printf("Added new employee (%s) to database at: %s\n", employee, file_path);
    return 0;
}