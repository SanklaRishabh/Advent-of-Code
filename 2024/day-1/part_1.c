#include <stdio.h>
#include <stdlib.h>

int comparator(const void *a, const void *b) {
  return (*(const int *)a > *(const int *)b) -
         (*(const int *)a < *(const int *)b);
}

int main(void) {
  FILE *file = fopen("input", "r");

  if (!file) {
    perror("File error:");

    return EXIT_FAILURE;
  }

  char string[15];
  int list_1[1000], list_2[1000];
  int index = 0;

  while (fgets(string, 20, file)) {
    list_1[index] = atoi(string);
    list_2[index++] = atoi(&string[8]);
  }

  qsort(list_1, 1000, sizeof(int), comparator);
  qsort(list_2, 1000, sizeof(int), comparator);

  int distance = 0;

  for (index = 0; index < 1000; ++index)
    distance += abs(list_1[index] - list_2[index]);

  printf("%d\n", distance);
  fclose(file);

  return EXIT_SUCCESS;
}
