#include <stdio.h>

/*
Can either set DEBUG mode with the following preprocessor directive:
#define DEBUG
OR compile with the -D flag:
gcc -DDEBUG variables.c -o variables
*/

int main()
{
    #ifdef DEBUG
    printf("Debugging enabled (%s:%d)\n", __FILE__, __LINE__);
    #endif

    int personID = 1;
    char personName[] = "John";

    personID += 1;

    printf("Person: %s, Person ID: %d\n", personName, personID);
    return 0;
}
