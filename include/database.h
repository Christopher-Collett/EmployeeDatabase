#ifndef DATABASE_H
#define DATABASE_H

struct database_header
{
    unsigned short version;
    unsigned short employees;
    unsigned int file_length;
};

int create_database(char *file_path);
int add_employee(char *file_path, char *employee);

#endif