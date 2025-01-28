#ifndef FILE_H
#define FILE_H

#include "database.h"

int read_header(const char *filename, struct database_header *header);

#endif