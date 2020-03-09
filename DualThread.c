#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#define row 5
#define col 5

struct matrices{
  int matrixA[row][col];
  int matrixB[row][col];
  int matrixC[row][col];
};

//////////////////////////////////////////////////////////// Printing All Matrices ////////////////////////////////////////////////////
void printMatrices(struct matrices mat)
{
  int i, j;
  for (i = 0; i < row; i++) {
    printf("\n");
    for (j = 0; j < col; j++) {
      printf("%d    ", mat.matrixA[i][j]);
    }
  }


  printf("\n\n\n");

  for (i = 0; i < row; i++) {
    printf("\n");
    for (j = 0; j < col; j++) {
      printf("%d    ", mat.matrixB[i][j]);
    }
  }

  printf("\n\n\n");

  for ( i = 0; i < row; i++) {
    printf("\n");
    for ( j = 0; j < col; j++) {
      printf("%d    ", mat.matrixC[i][j]);
    }
  }
  printf("\n\n\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void *threadA(void *m)
{
  struct matrices *mat;
  mat = (struct matrices*) m;

    int i, j, k;
      int r=(row/2)-1;
      printf("%d Row T1 \n", r );
        for (i = 0; i < row/2 ; i++)
        {
            for (j = 0; j < col; j++)
            {
                mat->matrixC[i][j] = 0;
                for (k = 0; k < row; k++)
                    mat->matrixC[i][j] += mat->matrixA[i][k]*mat->matrixB[k][j];
            }
        }
}

void *threadB(void *m)
{
  struct matrices *mat;
  mat = (struct matrices*) m;
  int r=row/2;
  printf("%d Row T2 \n", r );

    int i, j, k;

        for (i = row/2; i < row; i++)
        {
            for (j = col; j < col; j++)
            {
                mat->matrixC[i][j] = 0;
                for (k = row; k < row; k++)
                    mat->matrixC[i][j] += mat->matrixA[i][k]*mat->matrixB[k][j];
            }
        }
}

int main(int argc, char const *argv[]) {
  srand(time(0));

struct matrices mat;


  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        mat.matrixA[i][j] = (rand() % (5 - 1 + 1)) + 1;
        mat.matrixB[i][j] = (rand() % (5 - 1 + 1)) + 1;
    }
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      mat.matrixC[i][j]=0;
    }
  }

  pthread_t ida,idb;

  pthread_create(&ida, NULL, threadA, (void *)&mat);
  pthread_create(&idb, NULL, threadB, (void*)&mat);


 pthread_join(ida,NULL);
 pthread_join(idb,NULL);

 printMatrices(mat);

  return 0;
}
