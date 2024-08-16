#include "search.h"
#include "io-file.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void swap(Result *a, Result *b)
{

    Result temp = *a;
    *a = *b;
    *b = temp;
}

void printmatrinx(int **matrix, int len1, int len2)
{
    for (int i = 0; i < len1 + 1; i++)
    {
        for (int j = 0; j < len2 + 1; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void sort(Result *result, enum SORT mode, int len)
{
    if (len <= 1)
        return;

    int i = -1;
    int j = 0;
    int pivot = len - 1;

    while (j < pivot)
    {
        if (
            (mode == DESC) ^ (result[j].score <= result[pivot].score))
        {
            i++;
            swap(&result[i], &result[j]);
        }
        j++;
    }
    i++;
    swap(&result[i], &result[pivot]);

    // Recursively sort the partitions
    sort(result, mode, i);
    sort(result + i + 1, mode, len - i - 1);
}

int wagner_fischer_impl(char *__str1, char *__str2)
{
    printf("\n\n\n%s VS %s\n", __str1, __str2);
    int len1 = strlen(__str1);
    int len2 = strlen(__str2);

    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i < len1 + 1; i++)
        matrix[i][0] = i;

    for (int i = 0; i < len2 + 1; i++)
        matrix[0][i] = i;

    for (int i = 1; i < len1 + 1; i++)
        for (int j = 1; j < len2 + 1; j++)
            matrix[i][j] = (__str1[i - 1] == __str2[j - 1] ? 0 : 1) + MIN(matrix[i][j - 1], matrix[i - 1][j], matrix[i - 1][j - 1]);

    for (int i = 0; i < len1 + 1; i++)
    {
        for (int j = 0; j < len2 + 1; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return matrix[len1][len2];
}

Result *wagner_fischer(row *csv, char *string)
{
    Result *result = malloc(sizeof(Result) * NUMBER_OF_ROWS);
    for (int i = 0; i < NUMBER_OF_ROWS; i++)
    {
        result[i].index = i;
        result[i].score = wagner_fischer_impl(csv[i].disc, string);
    }

    sort(result, DESC, NUMBER_OF_ROWS);

    return result;
}