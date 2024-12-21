#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isSafe(int[], int);
bool applyDampener(int[], int);

int main(void) {
  FILE *file = fopen("input", "r");

  if (!file) {
    perror("File error");

    return EXIT_FAILURE;
  }

  char string[50];
  int array[25];
  int safeCount = 0;

  while (fgets(string, 50, file)) {
    int index = 0;
    char *token = strtok(string, " ");

    while (token) {
      array[index++] = atoi(token);
      token = strtok(NULL, " ");
    }

    (isSafe(array, index) || applyDampener(array, index)) && ++safeCount;
  }

  printf("%d\n", safeCount);
  fclose(file);

  return EXIT_SUCCESS;
}

bool isSafe(int arr[], int size) {
  bool isIncreasing = true, isDecreasing = true;

  for (int i = 0; i < size - 1; ++i) {
    int diff = arr[i] - arr[i + 1];

    if (!diff || diff < -3 || diff > 3)
      return false;

    if (diff < 0)
      isDecreasing = false;
    else
      isIncreasing = false;

    if (!isDecreasing && !isIncreasing)
      return false;
  }

  return true;
}

bool applyDampener(int arr[], int size) {
  int newArr[24];

  for (int i = 0; i < size; ++i) {
    int idx = 0;

    for (int j = 0; j < size; ++j)
      if (i != j)
        newArr[idx++] = arr[j];

    if (isSafe(newArr, idx))
      return true;
  }

  return false;
}