#include <stdio.h>

#include "../include/database.h"
#include "../include/file.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <database-path>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    struct database_header header = {0};

    if (read_header(filename, &header))
    {
        return 1;
    }

    printf("Database version: %d\n", header.version);
    printf("Number of employees: %d\n", header.employees);
    printf("File length: %d\n", header.file_length);

    return 0;
}
