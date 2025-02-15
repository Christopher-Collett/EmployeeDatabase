#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "database.h"

int create_database(char *file_path)
{
    struct database_header header =
    {
        .version = DATABASE_VERSION,
        .employees = 0,
    };

    int create_flags = O_RDWR | O_CREAT | O_EXCL;
    int user_rw_permissions = S_IRUSR | S_IWUSR;

    int fd = open(file_path, create_flags, user_rw_permissions);
    if (fd == -1)
    {
        fprintf(stderr, "Error: Failed to create database file: ");
        perror("open");
        return 1;
    }

    size_t bytes_written = write(fd, &header, sizeof(header));
    if (bytes_written != sizeof(header))
    {
        fprintf(stderr, "Error: wrote %ld bytes, expected %lu\n", bytes_written, sizeof(header));
        close(fd);
        return 1;
    }

    close(fd);
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