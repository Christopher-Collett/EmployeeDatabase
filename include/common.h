#ifndef COMMON_H
#define COMMON_H

typedef enum {
    SUCCESS,
    FAILURE
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