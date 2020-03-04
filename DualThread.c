#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#define row 50
#define col 50

struct matrices{
  int matrixA[row][col];
  int matrixB[row][col];
  int matrixC[row][col];
}


void *threadA(void *m)
{
  struct matrices *mat;
  mat = (struct matrices*) m;

    int i, j, k;
        for (i = 0; i < row/2; i++)
        {
            for (j = 0; j < row/2; j++)
            {
                mat.matrixC[i][j] = 0;
                for (k = 0; k < row/2; k++)
                    mat.matrixC[i][j] += mat.matrixA[i][k]*mat.matrixB[k][j];
            }
        }
}

void *threadB(void *mat)
{
  struct matrices *mat;
  mat = (struct matrices*) m;

    int i, j, k;
        for (i = row/2; i < row; i++)
        {
            for (j = row/2; j < row; j++)
            {
                mat.matrixC[i][j] = 0;
                for (k = row/2; k < row; k++)
                    mat.matrixC[i][j] += mat.matrixA[i][k]*mat.matrixB[k][j];
            }
        }
}

int main(int argc, char const *argv[]) {
  srand(time(0));

struct matrices mat;


  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        mat.matrixA[i][j] = (rand() % (10 - 1 + 1)) + 1;
        mat.matrixB[i][j] = (rand() % (10 - 1 + 1)) + 1;
    }
  }

  pthread_t ida,idb;

  pthread_create(&ida, NULL, threadA, (void *)mat);
  pthread_create(&idb,NULL, threadB, (void*)mat);


/*for (i = 0; i < row; i++) {
  printf("\n");
  for (j = 0; j < col; j++) {
    printf("%d    ", mat.matrixA[i][j]);
  }
}

for (i = 0; i < row; i++) {
  printf("\n");
  for (j = 0; j < col; j++) {
    printf("%d    ", mat.matrixB[i][j]);
  }
}

for (i = 0; i < row; i++) {
  printf("\n");
  for (j = 0; j < col; j++) {
    printf("%d    ", mat.matrixC[i][j]);
  }
}
*/
  return 0;
}
