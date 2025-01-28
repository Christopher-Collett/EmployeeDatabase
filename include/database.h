#ifndef DATABASE_H
#define DATABASE_H

struct database_header
{
    unsigned short version;
    unsigned short employees;
    unsigned int file_length;
};

#endif