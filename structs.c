#include <stdio.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char firstname[64];
    char lastname[64];
    float income;
    bool ismanager;
};

int main() {
    struct Employee e1 = {1, "John", "Doe", 50000.0, false};
    printf("Employee %s %s has an income of %.2f\n", e1.firstname, e1.lastname, e1.income);
    struct Employee employees[MAX_EMPLOYEES];
}