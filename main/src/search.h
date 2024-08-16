


#include"io-file.h"

enum SORT {
    ASC,
    DESC
};

typedef struct {
    int index , score;
} Result;

#define MIN(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))


void sort(Result* result, enum SORT sort, int len);
Result *wagner_fischer(row *csv, char *string) ; 
int wagner_fischer_impl(char *__str1, char *__str2); 
Result *search(row *csv , char* string);
