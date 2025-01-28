#include <stdio.h>

void foreach(char *arr[], int size, void (*f)(char *)) {
    /* this won't work as the parameter arr is a pointer to the original array, not the array itself
    int arrSizeInBytes = sizeof(arr);
    int elemSizeInBytes = sizeof(arr[0]);
    int size = arrSizeInBytes / elemSizeInBytes;
    */
    for (int i = 0; i < size; i++) {
        f(arr[i]);
    }
}

void print(char *s) {
    printf("%s\n", s);
}

int main(int argc, char *argv[]) { // argv is an array of pointers to constant strings
    printf("argc = %d\n", argc);
    /*
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    */
    foreach(argv, argc, print);
    return 0;
}
