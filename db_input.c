#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct database_header
{
    unsigned short version;
    unsigned short employees;
    unsigned int file_length;
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <database-path>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    struct database_header header = {0}; // make sure to clear out the struct memory

    ssize_t bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header))
    {
        fprintf(stderr, "Error: read %ld bytes, expected %lu\n", bytes_read, sizeof(header));
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}