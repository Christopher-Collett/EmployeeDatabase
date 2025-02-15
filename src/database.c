#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "database.h"
#include "common.h"

ResultCode create_database_file(char *file_path)
{
    int create_flags = O_RDWR | O_CREAT | O_EXCL;
    int user_rw_permissions = S_IRUSR | S_IWUSR;

    int fd = open(file_path, create_flags, user_rw_permissions);
    if (fd == -1)
    {
        fprintf(stderr, "Error: Failed to create database file: ");
        perror("open");
        return FAILURE;
    }
    close(fd);
    return SUCCESS;
}

struct ResultInt open_database_file(char *file_path)
{
    int fd = open(file_path, O_RDWR);
    if (fd == -1)
    {
        fprintf(stderr, "Error: Failed to open database file: ");
        perror("open");
        return (struct ResultInt) { .code = FAILURE };
    }
    return (struct ResultInt) { .code = SUCCESS, .value = fd };
}

ResultCode write_to_file(int fd, void *data, size_t size_of_data)
{
    size_t bytes_written = write(fd, data, size_of_data);
    if (bytes_written != size_of_data)
    {
        fprintf(stderr, "Error: wrote %ld bytes, expected %lu\n", bytes_written, size_of_data);
        return FAILURE;
    }
    return SUCCESS;
}

ResultCode update_header(char *file_path, struct database_header *header)
{
    struct ResultInt file_result = open_database_file(file_path);
    if (file_result.code == FAILURE) return FAILURE;
    int fd = file_result.value;

    ResultCode result = write_to_file(fd, header, sizeof(*header));

    close(fd);
    return result;
}

ResultCode create_database(char *file_path)
{
    struct database_header header =
    {
        .version = DATABASE_VERSION,
        .employees = 0,
    };

    ResultCode create_result = create_database_file(file_path);
    if (create_result == FAILURE) return FAILURE;

    ResultCode update_result = update_header(file_path, &header);
    if (update_result == FAILURE) return FAILURE;

    printf("Created new database at: %s\n", file_path);
    return SUCCESS;
}

ResultCode add_employee(char *file_path, char *employee)
{
    printf("Added new employee (%s) to database at: %s\n", employee, file_path);
    return SUCCESS;
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