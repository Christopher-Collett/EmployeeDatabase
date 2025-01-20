#include <stdio.h>

#define MAX_IDS 32

int main() {
    char message[] = "The maximum number of IDs is: ";

    printf("%s%d\n", message, MAX_IDS);

    int ids[MAX_IDS] = {0, 0b10110, 2}; // rest get's initialized to 0

    printf("%d\n", ids[1]);
    
    return 0;
}