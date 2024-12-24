#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEN_KB 10240

int findFunction(char[]);
bool findStart(char[], int, int *);
bool findStop(char[], int, int *);

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
  static bool enabled = true;
  int len = strlen(str), sum = 0;

  for (int i = 0; i < len; ++i) {
    if (enabled) {
      if (str[i] == 'm') {
        if (i + 4 < len && str[++i] == 'u' && str[++i] == 'l' &&
            str[++i] == '(' && isdigit(str[++i])) {
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
      } else if (str[i] == 'd')
        enabled = findStop(str, len, &i);
    } else
      enabled = findStart(str, len, &i);
  }

  return sum;
}

bool findStop(char str[], int size, int *idx) {
  if (*idx + 6 < size && str[++*idx] == 'o' && str[++*idx] == 'n' &&
      str[++*idx] == '\'' && str[++*idx] == 't' && str[++*idx] == '(' &&
      str[++*idx] == ')')
    return false;

  return true;
}

bool findStart(char str[], int size, int *idx) {
  if (*idx + 3 < size && str[*idx] == 'd' && str[++*idx] == 'o' &&
      str[++*idx] == '(' && str[++*idx] == ')')
    return true;

  return false;
}