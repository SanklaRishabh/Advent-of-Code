#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *file = fopen("input", "r");

  if (!file) {
    perror("File error");

    return EXIT_FAILURE;
  }

  char string[50];
  int array[20];
  int safeCount = 0;

  while (fgets(string, 50, file)) {
    char *token = strtok(string, " ");
    int index = 0;

    while (token) {
      array[index++] = atoi(token);
      token = strtok(NULL, " ");
    }

    bool isIncreasing = true, isDecreasing = true, isValid = true;

    for (int i = 0; i < index - 1; ++i) {
      int diff = array[i] - array[i + 1];

      if (!diff || diff < -3 || diff > 3) {
        isValid = false;

        break;
      }

      if (diff < 0)
        isDecreasing = false;
      else if (diff > 0)
        isIncreasing = false;

      if (!isDecreasing && !isIncreasing) {
        isValid = false;

        break;
      }
    }

    if (isValid)
      ++safeCount;
  }

  printf("%d\n", safeCount);
  fclose(file);

  return EXIT_SUCCESS;
}