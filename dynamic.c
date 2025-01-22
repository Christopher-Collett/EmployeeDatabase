#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 1000

typedef enum
{
    SUCCESS,
    FAILURE
} ReturnCode;

struct Employee
{
    int id;
    int income;
    bool staff;
};

void intialize_employee(struct Employee *e, int id)
{
    e->id = id;
    e->income = 0;
    e->staff = false;
}

ReturnCode add_employee(struct Employee **employees)
{
    static int numberEmployees = 0;
    numberEmployees++;
    struct Employee *temp = realloc(*employees, numberEmployees * sizeof(struct Employee));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return FAILURE;
    }
    *employees = temp; // using a temp to avoid freeing employees if realloc fails
    intialize_employee(&((*employees)[numberEmployees - 1]), numberEmployees);
    return SUCCESS;
}

int main()
{
    struct Employee *employees = malloc(sizeof(struct Employee));
    if (employees == NULL)
    {
        printf("Memory allocation failed\n"); // either free memory and try again or exit
        return 1;
    }

    for (int i = 0; i < 4; i++)
    {
        if (add_employee(&employees) == FAILURE)
        {
            printf("Failed to add employee\n");
            return 1;
        }
    }

    for (int i = 0; i < 4; i++)
        printf("Employee %d has an income of %d\n", employees[i].id, employees[i].income);

    free(employees);
    employees = NULL;
    return 0;
}