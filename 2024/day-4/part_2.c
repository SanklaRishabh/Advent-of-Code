#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool findDiagonals(char[140][142], int, int);

int main(void) {
  FILE *file = fopen("input", "r");

  if (!file) {
    perror("File error");

    return EXIT_FAILURE;
  }

  char grid[140][142] = {0};
  int i = 0;

  while (fgets(grid[i++], 142, file))
    ;

  fclose(file);

  int answer = 0;

  for (i = 0; i < 140; ++i)
    for (int j = 0; j < 140; ++j)
      if (grid[i][j] == 'A')
        answer += findDiagonals(grid, i, j);

  printf("%d\n", answer);

  return EXIT_SUCCESS;
}

bool findDiagonals(char grid[140][142], int i, int j) {
  int found = 0;

  if (i - 1 >= 0 && i + 1 < 140 && j - 1 >= 0 && j + 1 < 140) {
    switch (grid[i - 1][j - 1]) {
    case 'M':
      grid[i + 1][j + 1] == 'S' ? ++found : false;

      break;
    case 'S':
      grid[i + 1][j + 1] == 'M' ? ++found : false;

      break;
    }

    switch (grid[i - 1][j + 1]) {
    case 'M':
      grid[i + 1][j - 1] == 'S' ? ++found : false;

      break;
    case 'S':
      grid[i + 1][j - 1] == 'M' ? ++found : false;

      break;
    }
  }

  return found == 2;
}