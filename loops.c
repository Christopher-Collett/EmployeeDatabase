#include <stdio.h>
#include <string.h>

#define MAX_IDS 32

int main() {
    // MUST specifically initialize all elements to 0, or else they will contain garbage values
    int ids[MAX_IDS] = {0};

    for (int i = 0; i < MAX_IDS; i++) {
        printf("ID %d: %d\n", i, ids[i]);
    }

    // can loop over a string by incrementing a pointer
    char name[] = "John Doe";
    char *letter = name; // pointer to the first character of the character array
    while (strcmp(letter, "\0") != 0) { // loop until the null terminator is reached
        printf("%c", *letter);
        letter++; // increment the pointer to the next character
    }
    printf("\n");

    return 0;
}