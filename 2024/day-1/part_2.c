#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *file = fopen("input", "r");

  if (!file) {
    perror("File error:");

    return EXIT_FAILURE;
  }

  char string[15];
  int list_1[1000];
  int list_2[100000] = {0};
  int index = 0;

  while (fgets(string, 15, file)) {
    list_1[index++] = atoi(string);
    ++list_2[atoi(&string[8])];
  }

  int score = 0;

  for (index = 0; index < 1000; ++index)
    score += list_1[index] * list_2[list_1[index]];

  printf("%d\n", score);
  fclose(file);

  return EXIT_SUCCESS;
}
