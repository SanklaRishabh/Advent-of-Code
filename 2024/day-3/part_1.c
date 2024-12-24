#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEN_KB 10240

int findFunction(char[]);

int main(void) {
  FILE *file = fopen("input", "r");

  if (!file) {
    perror("File error");

    return EXIT_FAILURE;
  }

  char string[TEN_KB];
  int answer = 0;

  while (fgets(string, TEN_KB, file))
    answer += findFunction(string);

  printf("%d\n", answer);
  fclose(file);

  return EXIT_SUCCESS;
}

int findFunction(char str[]) {
  int sum = 0, len = strlen(str);

  for (int i = 0; i < len; ++i)
    if (i + 4 < len && str[i] == 'm' && str[++i] == 'u' && str[++i] == 'l' && str[++i] == '(' && isdigit(str[++i])) {
      int x = atoi(&str[i]), temp = x, digits = 0;

      while (temp)
        temp /= 10, ++digits;

      i += digits;

      if (i + 1 < len && str[i] == ',' && isdigit(str[++i])) {
        int y = atoi(&str[i]);
        temp = y;
        digits = 0;

        while (temp)
          temp /= 10, ++digits;

        i += digits;

        if (i < len && str[i] == ')')
          sum += x * y;
      }
    }

  return sum;
}