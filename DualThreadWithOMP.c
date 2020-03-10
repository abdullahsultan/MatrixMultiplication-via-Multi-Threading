#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>


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
  ///////////////////////threadA///////////////////////
#pragma omp prallel
{

    int i, j, k;
        for (i = 0; i < row/2 ; i++)
        {
            for (j = 0; j < col; j++)
            {
                mat.matrixC[i][j] = 0;
                for (k = 0; k < row; k++)
                    mat.matrixC[i][j] += mat.matrixA[i][k]*mat.matrixB[k][j];
            }
        }
      }
  //////////////////////////////////////////////////////

  //////////////////////////threadB///////////////////////



    int i, j, k;

        for (i = row/2; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                mat.matrixC[i][j] = 0;
                for (k = 0; k < row; k++)
                    mat.matrixC[i][j] += mat.matrixA[i][k]*mat.matrixB[k][j];
            }
        }

  ///////////////////////////////////////////////////////

 printMatrices(mat);

  return 0;
}
