#include "problem3.h"

void rotatematrix(int m, int n, int mat[R][C])
{
   int row = 0, col = 0;
   int pre, curr;

   /*
   row - Staring row index
   m - ending row index
   col - starting column index
   n - ending column index
   */
   while (row < m && col < n)
   {

       if (row + 1 == m || col + 1 == n)
           break;


       pre = mat[row + 1][col];


       for (int i = col; i < n; i++)
       {
           curr = mat[row][i];
           mat[row][i] = pre;
           pre = curr;
       }
       row++;


       for (int i = row; i < m; i++)
       {
           curr = mat[i][n-1];
           mat[i][n-1] = pre;
           pre = curr;
       }
       n--;


       if (row < m)
       {
           for (int i = n-1; i >= col; i--)
           {
               curr = mat[m-1][i];
               mat[m-1][i] = pre;
               pre = curr;
           }
       }
       m--;

       if (col < n)
       {
           for (int i = m-1; i >= row; i--)
           {
               curr = mat[i][col];
               mat[i][col] = pre;
               pre = curr;
           }
       }
       col++;
   }

   // Print rotated matrix
   for (int i=0; i<R; i++)
   {
       for (int j=0; j<C; j++)
       cout << mat[i][j] << " ";
       cout << endl;
   }
}
