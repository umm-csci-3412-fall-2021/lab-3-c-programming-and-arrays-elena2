#include "array_merge.h"
#include <stdlib.h>
#include "../mergesort/mergesort.c"

// Personal access token: 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
int calculateSize(int *sizes, int num_arrays) {
    int total = 0;
    for (int i = 0; i < num_arrays; i++) {
        total = total + sizes[i];
    }
    return total;
}

int *removeDuplicatesFrom(int *values, int size) {
    int index = 0;
    int j = 1;
    int len, n;
    int *unique, *final;
    unique = (int *) calloc(size, sizeof(int));
    unique[0] = values[0];
    for (int i = 1; i < size; i++) {
        if (values[i] != unique[j - 1]) {
            unique[j] = values[i];
            index++;
            j++;
        }
    }
    len = index + 2;
    n = index + 1;
    final = (int *) calloc(len, sizeof(int));
    final[0] = n;
    for (int i = 1; i < len; i++) {
        final[i] = unique[i - 1];
    }
    free(unique);
    return final;
}

int *array_merge(int num_arrays, int *sizes, int **values) {
    if(num_arrays == 0){
        int* placeholder = (int*)calloc(1, sizeof(int));
        placeholder[0] = 0;
        return placeholder;
    }

    int size = calculateSize(sizes, num_arrays);
    int *merged = (int *) calloc(size + 1, sizeof(int));
    int *unique;

    int index = 0;

    for (int i = 0; i < num_arrays; i++) {
        int *current = values[i];
        for (int j = 0; j < sizes[i]; j++) {
            merged[index] = current[j];
            index++;
        }
    }
    mergesort(size, merged);
    unique = removeDuplicatesFrom(merged, size);
    free(merged);
    return unique;
}
