#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"io-file.h"
#include"search.h"
 
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
int main(int argc, char const *argv[]) {
    row csv[NUMBER_OF_ROWS]; // Allocate array on the stack

    FILE *file = fopen(CHEAT_SHEET_BIN, "rb"); // Open file for reading in binary mode
    if (file == NULL) {
        perror("Error opening file");
        return -1; // Return an error code
    }

    // Read the data into the array
    size_t read_count = fread(csv, sizeof(row), NUMBER_OF_ROWS, file);
    if (read_count != NUMBER_OF_ROWS) {
        perror("Error reading file");
        fclose(file);
        return -1; // Return an error code
    }

    fclose(file); // Close the file


    for (int i = 0; i < NUMBER_OF_ROWS; i++) {
        printf("%s - %s\n", csv[i].disc, csv[i].code);
    }



    Result *result = wagner_fischer(csv , "nf-fa-wind"); //  search(csv , "wind");
    for (int i = 0; i < NUMBER_OF_ROWS; i++) 
        printf("%d : %s\n", result[i].score, csv[result[i].index].disc);


    printf("\n%d\n",wagner_fischer_impl("nf-weather-windy" , "windy"));
    printf("\n%d\n",wagner_fischer_impl("nf-fa-wind" , "windy"));

    


    printf("Hello World\n");
    return 0;
}
#endif