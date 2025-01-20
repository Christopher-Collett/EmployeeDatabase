#include <stdio.h>

int main() {
    int temp;
    printf("Enter the temperature: ");
    scanf("%d", &temp);

    if (temp >= 70) {
        printf("At %d, it's hot outside!\n", temp);
    }
    else if (temp >= 30) {
        printf("At %d, it's nice outside!\n", temp);
    }
    else {
        printf("At %d, it's cold outside!\n", temp);
    }

    return 0;
}
