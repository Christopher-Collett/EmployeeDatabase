#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "database.h"

int create_database(char *file_path)
{
    printf("Created new database at: %s\n", file_path);
    return 0;
}

int add_employee(char *file_path, char *employee)
{
    printf("Added new employee (%s) to database at: %s\n", employee, file_path);
    return 0;
}

// Read the database header from specified file.
// Returns 0 on success, 1 on failure.
int _read_header(const char *filename, struct database_header *header)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    size_t bytes_read = read(fd, header, sizeof(*header));
    if (bytes_read != sizeof(*header))
    {
        fprintf(stderr, "Error: read %ld bytes, expected %lu\n", bytes_read, sizeof(*header));
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}