#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#define row 50
#define col 50

int main(int argc, char const *argv[]) {
  int matrixA[row][col];
  int matrixB[row][col];
  int matrixC[row][col];
  srand(time(0));

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        matrixA[i][j] = (rand() % (10 - 1 + 1)) + 1;
        matrixB[i][j] = (rand() % (10 - 1 + 1)) + 1;
    }
  }

  int i, j, k;
      for (i = 0; i < row; i++)
      {
          for (j = 0; j < row; j++)
          {
              matrixC[i][j] = 0;
              for (k = 0; k < row; k++)
                  matrixC[i][j] += matrixA[i][k]*matrixB[k][j];
          }
      }

for (i = 0; i < row; i++) {
  printf("\n");
  for (j = 0; j < col; j++) {
    printf("%d    ", matrixA[i][j]);
  }
}

for (i = 0; i < row; i++) {
  printf("\n");
  for (j = 0; j < col; j++) {
    printf("%d    ", matrixB[i][j]);
  }
}

for (i = 0; i < row; i++) {
  printf("\n");
  for (j = 0; j < col; j++) {
    printf("%d    ", matrixC[i][j]);
  }
}

  return 0;
}
