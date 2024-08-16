#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"io-file.h"

 
#ifdef CSV
int main(int argc, char const *argv[])
{
    printf("Hello World\n");
    printf(" e31e\n");
    row *csv = read();

    store(csv);
    printf("\ue31e\n");
    return 0;
}


#else

int main(int argc, char const *argv[])
{
    row *csv = read();
    for (int i = 0; i < NUMBER_OF_ROWS; i++)
        printf("%s - %s \n", csv[i].disc , csv[i].code);
    
    printf("Hello World\n");
    return 0;
}

#endif