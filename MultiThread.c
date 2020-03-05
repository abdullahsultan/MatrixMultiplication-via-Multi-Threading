#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#define row 4
#define col 4

struct matrices{
  int i,j,ttt;
  int matrixA[row][col];
  int matrixB[row][col];
  int matrixC[row][col];
  pthread_t ida[row*col];
};


void *threadA(void *m)
{
  struct matrices *mat;
  mat = (struct matrices*) m;

      mat->matrixC[mat->i][mat->j] = 0;
      for (int k = 0; k < row ; k++)
        mat->matrixC[mat->i][mat->j] += mat->matrixA[mat->i][k]*mat->matrixB[k][mat->j];

        printf("\n thread=%ld : row=%d : col=%d : result=%d \n",mat->ida[mat->ttt],mat->i,mat->j,mat->matrixC[mat->i][mat->j] );
}


int main(int argc, char const *argv[]) {
  srand(time(0));

struct matrices mat;
int i,j;

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
        mat.matrixA[i][j] = (rand() % (5 - 1 + 1)) + 1;
        mat.matrixB[i][j] = (rand() % (5 - 1 + 1)) + 1;
    }
  }
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      mat.matrixC[i][j]=0;
    }
  }

//  pthread_t ida[row][col];
mat.ttt=0;
for (mat.i = 0; mat.i < row; mat.i++) {
  for (mat.j = 0; mat.j < col ; mat.j++)
  {
      pthread_create(&mat.ida[mat.ttt], NULL, threadA, (void *)&mat);
    //  mat.ida[mat.ttt];
  }
}
for (mat.i = 0; mat.i < row; mat.i++) {
  for (mat.j = 0; mat.j < col ; mat.j++)
  {
    pthread_join(mat.ida[mat.ttt],NULL);
  }
}



for (i = 0; i < row; i++) {
  printf("\n");
  for (int j = 0; j < col; j++) {
    printf("%d    ", mat.matrixA[i][j]);
  }
}

printf("\n\n\n");

for (i = 0; i < row; i++) {
  printf("\n");
  for (int j = 0; j < col; j++) {
    printf("%d    ", mat.matrixB[i][j]);
  }
}

printf("\n\n\n");

for (i = 0; i < row; i++) {
  printf("\n");
  for (int j = 0; j < col; j++) {
    printf("%d    ", mat.matrixC[i][j]);
  }
}

  return 0;
}
