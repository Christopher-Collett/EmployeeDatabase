#ifndef COMMON_H
#define COMMON_H

typedef enum {
    SUCCESS = 0,
    FAILURE = 1,
} ResultCode ;

struct ResultInt {
    ResultCode code;
    int value;
};

struct ResultStr {
    ResultCode code;
    char *value;
};

#endif