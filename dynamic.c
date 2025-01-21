#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 1000

struct Employee
{
    int id;
    int income;
    bool staff;
};

void intialize_employee(struct Employee *e)
{
    e->id = 0;
    e->income = 0;
    e->staff = false;
}

int main()
{
    int n = 4;
    struct Employee *employees = malloc(sizeof(struct Employee) * n);
    if (employees == NULL)
    {
        printf("Memory allocation failed\n"); // either free memory and try again or exit
        return 1;
    }

    for (int i = 0; i < n; i++)
        intialize_employee(&employees[i]);

    for (int i = 0; i < n; i++)
        printf("Employee %d has an income of %d\n", employees[i].id, employees[i].income);

    free(employees);
    employees = NULL;
    return 0;
}