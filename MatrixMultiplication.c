/**
This program reads in two files "p3_a.in" and "p3_b.in" containing integer matrices of size 3 x
3. It then calculates the product of the matrices in a new matrix. The resulting sum matrix
is then saved to the file "p3.res"

@author Tarek Solamy
@version 1.0 10/19/2022
 */

#include <stdio.h>

#define ROW 3
#define COL 3


/* Function declarations */
// this function will scan the matrix in p3_a.in to a 2D array
void file1(int matrix1 [][COL], FILE* file_pointer);
// this function will scan the matrix in p3_b.in to a 2D array
void file2(int matrix2 [][COL], FILE* file_pointer);
// this function will perform matrix multiplication on matrix 1 and 2 and put the output in p3.res
void matrixMultiply(int mat1[][COL], int mat2[][COL], int res[][COL]);



int main()
{
  int mat1 [ROW][COL];
  int mat2 [ROW] [COL];
  int res [ROW] [COL];
  FILE* file_pointer;
  printf("Entering elements of first matrix from file \n");
  printf("First Matrix: \n");
  file1(mat1, file_pointer);
  printf("Entering elements of second matrix from file \n");
  printf("Second Matrix: \n");
  file2(mat2,file_pointer);
  printf("Output Matrix: \n");
  matrixMultiply(mat1, mat2, res);
    return 0;
}

void file1(int mat1 [][COL], FILE* file_pointer){
  file_pointer=fopen("p3_a.in", "r");
  int n=0;
  int (*p1)[3]= mat1;
  int (*reset)[3]=mat1;
  int *p2 = NULL;
  p2= *p1;

  while( fscanf(file_pointer, "%d ", &n) > 0 )
     {
       *p2=n;
       p2++;
       if (p2==*p1+2){
         p1++;
       }
     }

     fclose(file_pointer);
     p1=reset;
     for (; p1 != mat1+ROW ;++p1){
       for (p2 = *p1; p2 != *p1+COL ;++p2){
         printf("%i ", *p2);
       }
       printf("\n");

     }


}
void file2(int mat2 [][3], FILE* file_pointer){
  file_pointer=fopen("p3_b.in", "r");
  int n=0;
  int (*p1)[3]= mat2;
  int (*reset)[3]=mat2;
  int *p2 = NULL;
  p2= *p1;

  while( fscanf(file_pointer, "%d ", &n) > 0 )
     {
       *p2=n;
       p2++;
       if (p2==*p1+2){
         p1++;
       }
     }

     fclose(file_pointer);
     p1=reset;
     for (; p1 != mat2+ROW ;++p1){
       for (p2 = *p1; p2 != *p1+COL ;++p2){
         printf("%i ", *p2);
       }
       printf("\n");

     }

}



void matrixMultiply(int mat1[][COL], int mat2[][COL], int res[][COL])
{
  FILE* file_pointer;
  file_pointer=fopen("p3.res", "w");
  int (*p1)[3]= res;
  int (*reset)[3]=res;
  int *p2 = NULL;
  p2= *p1;
  int (*m1p1)[3]= mat1;
  int (*reset1)[3]=mat1;
  int *m1p2 = NULL;
  m1p2= *m1p1;
  int (*m2p1)[3]= mat2;
  int (*reset2)[3]=mat2;
  int *m2p2 = NULL;
  m2p2= *m2p1;
  for (; p1 != res+ROW ;++p1){
    m2p1=reset2;
    m2p2= *m2p1;
    for (p2 = *p1; p2 != *p1+COL ;++p2){
      m1p1=reset1;
      m1p2= *m1p1;
      int k=0;
      int sum=0;
      while (k<3){
        int n1= *m1p2;
        //printf("%i ", n1);
        int n2= *m2p2;
        //printf("%i ", n2);
        sum+=n1*n2;
        m1p2++;
        m2p2=m2p2+3;
        k++;
        //printf("\n");
        }
        *p2=sum;
        m2p2=m2p2-8;

        //printf("\n");
      }

      reset1++;
  }
  p1=reset;

  for (; p1 != res+ROW ;++p1){
    for (p2 = *p1; p2 != *p1+COL ;++p2){
      printf("%i ", *p2);
    }
    printf("\n");
  }

  p1=reset;

  for (; p1 != res+ROW ;++p1){
    for (p2 = *p1; p2 != *p1+COL ;++p2){
      fprintf(file_pointer, "%i", *p2);
      if(p2!=*p1+2){
        fprintf(file_pointer, " ");
      }
    }
    if(p1!=res+2){
      fprintf(file_pointer, "\n");
    }
  }



  fclose(file_pointer);

}
