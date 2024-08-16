

#include "stdio.h"
#include "malloc.h"

#include "io-file.h"

#ifdef CSV
row *read()
{
    printf("read\n");

    printf("read\n");

    FILE *file = fopen(CHEAT_SHEET_CSV, "r");
    if (!file)
    {
        perror("Failed to open file");
        return NULL;
    }

    // Allocate memory for rows
    row *csv = (row *)malloc(sizeof(row) * NUMBER_OF_ROWS);
    if (!csv)
    {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    int i = 0;
    while (i < NUMBER_OF_ROWS)
    {
        // Read a line into the structure
        int result = fscanf(file, "%[^,],%[^\n]\n", csv[i].disc, csv[i].code);
        if (result == 2)
        {
            // Successfully read one row
            printf("%s - %s\n", csv[i].disc, csv[i].code);
            i++;
        }
        else if (result == EOF)
        {
            // End of file reached
            break;
        }
        else
        {
            // Error reading the line
            perror("Error reading line");
            break; // Or handle error appropriately
        }
    }

    fclose(file);

    // Adjust the size of allocated memory to the number of rows actually read
    csv = (row *)realloc(csv, sizeof(row) * i);
    printf("THE INDEX IS %d\n", i);
    return csv;
}

void store(row *data)
{

    FILE *file = fopen(CHEAT_SHEET_BIN, "wb"); // Open file for writing in binary mode
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    fwrite(data, sizeof(row) * NUMBER_OF_ROWS, 1, file); // Write the variable to the file

    fclose(file); // Close the file
}

#else

row *read()
{

    return NULL;
}

#endif