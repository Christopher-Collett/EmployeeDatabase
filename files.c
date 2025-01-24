#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <io.h>

int main(int argc, char *argv[])
{
    /* File descriptors:
     * 0 = stdin
     * 1 = stdout
     * 2 = stderr
     */

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    int fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    char *header = "Hello, world!\n";
    int bytesToWrite = strlen(header);

    int bytesWritten = write(fd, header, bytesToWrite);
    if (bytesWritten == -1)
    {
        perror("write");
        return 1;
    }
    else if (bytesWritten != bytesToWrite)
    {
        fprintf(stderr, "write: wrote %d bytes, expected %d\n", bytesWritten, bytesToWrite);
        return 1;
    }

    return 0;
}