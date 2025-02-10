#ifndef DATABASE_H
#define DATABASE_H

static const unsigned short DATABASE_VERSION = 1;

struct database_header
{
    unsigned short version;
    unsigned short employees;
};

int create_database(char *file_path);
int add_employee(char *file_path, char *employee);

#endif