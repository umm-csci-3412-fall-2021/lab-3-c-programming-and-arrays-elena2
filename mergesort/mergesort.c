#include "mergesort.h"
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>


int needsSorting(int rangeSize) {
    int result = 0;
    if(rangeSize>=2){
        result = 1;
    }
    return result;
  }

void mergeRanges(int* values, int startIndex, int midPoint, int endIndex) {

    int rangeSize = endIndex - startIndex;
    int* destination = (int*)calloc(rangeSize, sizeof(int));
    int firstIndex = startIndex;
    int secondIndex = midPoint;
    int copyIndex = 0;
    int i;
    while (firstIndex < midPoint && secondIndex < endIndex) {
      if (values[firstIndex] < values[secondIndex]) {
        destination[copyIndex] = values[firstIndex];
        ++firstIndex;
      } else {
        destination[copyIndex] = values[secondIndex];
        ++secondIndex;
      }
      ++copyIndex;
    }
    while (firstIndex < midPoint) {
      destination[copyIndex] = values[firstIndex];
      ++copyIndex;
      ++firstIndex;
    }
    while (secondIndex < endIndex) {
      destination[copyIndex] = values[secondIndex];
      ++copyIndex;
      ++secondIndex;
    }
    for (i = 0; i < rangeSize; ++i) {
      values[i + startIndex] = destination[i];
    }
    if(rangeSize != 0){
        free(destination);
    }

  }

void mergesortRange(int* values, int startIndex, int endIndex) {
    int rangeSize = endIndex - startIndex;
    if (needsSorting(rangeSize) == 1) {
      int midPoint = (startIndex + endIndex) / 2;
      mergesortRange(values, startIndex, midPoint);
      mergesortRange(values, midPoint, endIndex);
      mergeRanges(values, startIndex, midPoint, endIndex);
    }
  }

  void mergesort(int size, int* values) {

    mergesortRange(values, 0, size);

}
