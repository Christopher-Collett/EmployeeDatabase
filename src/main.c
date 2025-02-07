#include <string.h>
#include <stdio.h>

#include "../include/database.h"
#include "../include/file.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <file> [options]\n", argv[0]);
        return 1;
    }
    char *file_path = argv[1];

    if (argc >= 3)
    {
        char *flag = argv[2];
        if (strcmp(flag, "-n") == 0)
        {
            printf("Creating new database at: %s\n", file_path);
            return create_database(file_path);
        }
    }

    return 0;
}
