#ifndef UTIL_H_
#define UTIL_H_

#define RETURN_IF(result, returnVal)  \
if(returnVal) {                       \
    perror("error:");                 \
    exit(result);                     \
}

#endif