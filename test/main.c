#include <stdio.h>

enum SORT {
    ASC,
    DESC
};

void swap(int *a, int *b)
{
    if (a != b) {
        *b = (*a) ^ (*b);
        *a = (*a) ^ (*b);
        *b = (*a) ^ (*b);
    }
}

void sort(int *result, enum SORT mode, int len)
{
    if (len <= 1) return;

    int i = -1;
    int j = 0;
    int pivot = len - 1;

    while (j < pivot) {
        if ((mode == DESC) ^ (result[j] <= result[pivot])) 
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



int main(int argc, char const *argv[]) {
    int array1[] = { 10, 7, 8, 9, 1, 5 };
    int len1 = sizeof(array1) / sizeof(array1[0]);

    int array2[] = { 3, 3, 2, 1, 5, 7 };
    int len2 = sizeof(array2) / sizeof(array2[0]);

    int array3[] = { 10, -3, 4, 2, 8, 15 };
    int len3 = sizeof(array3) / sizeof(array3[0]);

    // Test array1 with ascending order
    printf("Array 1 (ASC): ");
    sort(array1, ASC, len1);
    for (int i = 0; i < len1; i++)
        printf("%d ", array1[i]);
    printf("\n");

    // Test array2 with descending order
    printf("Array 2 (DESC): ");
    sort(array2, DESC, len2);
    for (int i = 0; i < len2; i++)
        printf("%d ", array2[i]);
    printf("\n");

    // Test array3 with ascending order
    printf("Array 3 (ASC): ");
    sort(array3, ASC, len3);
    for (int i = 0; i < len3; i++)
        printf("%d ", array3[i]);
    printf("\n");

    return 0;
}