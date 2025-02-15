#ifndef DATABASE_H
#define DATABASE_H

#include "common.h"

static const unsigned short DATABASE_VERSION = 1;

struct database_header
{
    unsigned short version;
    unsigned short employees;
};

ResultCode create_database(char *file_path);
ResultCode add_employee(char *file_path, char *employee);

#endif