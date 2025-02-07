#include <string.h>
#include <stdio.h>

#include "../include/database.h"
#include "../include/file.h"

int error_message(char *this_file)
{
    fprintf(stderr, "Usage: %s <file> [options] -- minimum one option required\n", this_file);
    return 1;
}

char get_flag(char *input)
{
    const char empty = '\0';
    if (strlen(input) != 2) return empty;
    if (input[0] != '-') return empty;
    return input[1];
}

int main(int argc, char *argv[])
{
    if (argc < 3) return error_message(argv[0]);

    char *file_path = argv[1];
    char flag = get_flag(argv[2]);

    switch (flag)
    {
        case 'n':
            printf("Creating new database at: %s\n", file_path);
            return create_database(file_path);
        default:
            return error_message(argv[0]);
    }
}