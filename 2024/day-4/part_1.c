#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const char string[] = "XMAS";

int findString(char[140][142], int, int);

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
      if (grid[i][j] == 'X') {
        answer += findString(grid, i, j);
      }

  printf("%d\n", answer);

  return EXIT_SUCCESS;
}

int findString(char grid[140][142], int i, int j) {
  int found = 0;

  for (int dx = -1; dx < 2; ++dx)
    for (int dy = -1; dy < 2; ++dy) {
      bool valid = true;

      for (int k = 0; k < 4; ++k) {
        int row = i + dx * k;
        int col = j + dy * k;

        if (row < 0 || row >= 140 || col < 0 || col >= 140 ||
            grid[row][col] != string[k])
          valid = false;
      }

      valid ? ++found : false;
    }

  return found;
}