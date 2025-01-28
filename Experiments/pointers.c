#include <stdio.h>

struct Employee
{
    char *name;
    int hoursWorked;
};

void initializeEmployee(struct Employee *e)
{
    e->name = "<no name>";
    e->hoursWorked = 0;
}

int main()
{
    int x = 10;
    int *p = &x;

    printf("Value of x at address %p is %d\n", p, *p);

    int *nullPointer;

    printf("Null pointer points to address %p\n", nullPointer);
    // this will cause a segmentation fault
    //printf("Null pointer value is %d\n", *nullPointer);

    struct Employee ralph;
    initializeEmployee(&ralph);
    printf("Employee %s has worked %d hours\n", ralph.name, ralph.hoursWorked);

    return 0;
}