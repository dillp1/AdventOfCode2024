#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 1000

void bubbleSort(int[]);

int main(int argc, char **argv)
{
    // open text file
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "ERROR - file not found\n");
    }

    // make two arrays
    int arr1[ARR_SIZE];
    int arr2[ARR_SIZE];

    // build array1
    for (int i = 0; i < ARR_SIZE; i++)
    {
        // scan left num
        fscanf(file, "%d", &arr1[i]);
        // discard right num
        fscanf(file, "%*d");
    }

    // rewind file
    rewind(file);

    // buld array 2
    for (int i = 0; i < ARR_SIZE; i++)
    {
        // discard left num
        fscanf(file, "%*d");
        // scan right num
        fscanf(file, "%d", &arr2[i]);
    }

    // sort arrays
    bubbleSort(arr1);
    bubbleSort(arr2);

    // find diff
    int sum_diff = 0;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        sum_diff += abs(arr1[i] - arr2[i]);
    }

    printf("Difference: %d\n", sum_diff);

    return EXIT_SUCCESS;
}

void bubbleSort(int x[])
{
    int num_passes;
    int lcv;
    int temp;

    for (num_passes = 1; num_passes < ARR_SIZE; num_passes++)
    {
        for (lcv = 0; lcv < ARR_SIZE - num_passes; lcv++)
        {
            if (x[lcv] > x[lcv + 1])
            {
                temp = x[lcv];
                x[lcv] = x[lcv + 1];
                x[lcv + 1] = temp;
            }
        }
    }
}
