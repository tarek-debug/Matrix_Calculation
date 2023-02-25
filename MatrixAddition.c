/*
 This program reads in two files "p3_a.in" and "p3_b.in" containing integer matrices of size 3 x
3. It then calculates the product of the matrices in a new matrix. The resulting sum matrix
is then saved to the file "p3.res"

 @author Tarek Solamy
 @version 1.0 10/06/2022
 */

#include <stdio.h>
// this function will scan the matrix in p3_a.in to a 2D array
void file1(int matrix1 [][3], FILE* file_pointer);
// this function will scan the matrix in p3_b.in to a 2D array
void file2(int matrix2 [][3], FILE* file_pointer);
// this function will perform matrix multiplication on matrix 1 and 2 and put the output in p3.res
void file3(int matrix1 [][3], int matrix2 [][3], int matrix3 [][3] , FILE* file_pointer);

int main (){
   int matrix1 [3][3];
   int matrix2 [3] [3];
   int matrix3 [3] [3];
   FILE* file_pointer;
   printf("Entering elements of first matrix from file \n");
   printf("First Matrix: \n");
   file1(matrix1, file_pointer);
   printf("Entering elements of second matrix from file \n");
   printf("Second Matrix: \n");
   file2(matrix2,file_pointer);
   printf("Output Matrix: \n");
   file3(matrix1, matrix2, matrix3, file_pointer);

   return 0;
}

void file1(int  matrix1 [][3], FILE* file_pointer){
  file_pointer=fopen("p3_a.in", "r");
  int i=0, j=0 , n=0;
  while( fscanf(file_pointer, "%d ", &n) > 0 )
     {
       matrix1[i][j++] = n;
       if (j==3){
         j=0;
         i++;
       }
     }
     fclose(file_pointer);

  for (int i=0 ; i< 3 ;i ++){
    for (int j=0 ; j< 3 ;j ++){
      printf("%i ", matrix1[i][j]);
    }
    printf("\n");

  }
  //printf("\n");

}

void file2(int matrix2 [][3], FILE* file_pointer){
  file_pointer=fopen("p3_b.in", "r");
  int i=0, j=0 , n=0;
  while( fscanf(file_pointer, "%d ", &n) > 0 )
     {
       matrix2[i][j++] = n;
       if (j==3){
         j=0;
         i++;
       }
     }
     fclose(file_pointer);

  for (int i=0 ; i< 3 ;i ++){
    for (int j=0 ; j< 3 ;j ++){
      printf("%i ", matrix2[i][j]);
    }
    printf("\n");

  }
  //printf("\n");
}

void file3(int matrix1 [][3], int matrix2 [][3], int matrix3 [] [3] , FILE* file_pointer){

  for (int i=0 ; i< 3 ;i ++){
    for (int j=0 ; j< 3 ;j ++){
      int matrix1_row=i;
      int matrix1_col=0;
      int matrix2_row=0;
      int matrix2_col=j;
      int k=0;
      int sum=0;
      while (k<3){
        sum+=matrix1[i][matrix1_col]*matrix2[matrix2_row][j];
        //printf("%i ", matrix1[i][matrix1_col]);
        //printf("%i ", matrix2[matrix2_row][j]);
        //printf("\n");
        matrix1_col++;
        matrix2_row++;
        k++;
      }
      //printf("\n");

      matrix3[i][j]=sum;
    }
  }
  for (int i=0 ; i< 3 ;i ++){
    for (int j=0 ; j< 3 ;j ++){
      printf("%i ", matrix3[i][j]);
    }
    printf("\n");

  }
  printf("\n");

  file_pointer= fopen("p3.res", "w");

  for (int i=0 ; i< 3 ;i ++){
    for (int j=0 ; j< 3 ;j ++){

      fprintf(file_pointer, "%i", (matrix3[i][j]));
      if (j<2){
        fprintf(file_pointer, " ");
      }
    }
    if (i<2){
      fprintf(file_pointer, "\n");

    }

  }
}
