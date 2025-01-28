#include <stdio.h>

int main() {
    char name[100];
    char address[100];
    int hoursWorked;

    printf("Enter your name, address, and hours worked, seperated by a comma: ");
    scanf("%[^,]%*c %[^,]%*c %d", name, address, &hoursWorked);

    /*
    printf("Enter your name: ");
    scanf("%[^\n]%*c", name);

    printf("Enter your address: ");
    scanf("%[^\n]%*c", address);

    printf("Enter your hours worked: ");
    scanf("%d", &hoursWorked);
    */

    printf("Name: %s\nAddress: %s\nHours Worked: %d\n", name, address, hoursWorked);

    if (hoursWorked > 40) {
        printf("You get overtime pay!\n", hoursWorked);
    }
    else {
        printf("You don't get overtime pay.\n", hoursWorked);
    }
    
    return 0;
}

