#include <stdio.h>
#include <math.h>

// From http://www.sanfoundry.com/c-program-find-inverse-matrix/

float determinant(float [][25], float);
void cofactor(float [][25], float);
void transpose(float [][25], float [][25], float);

int main()
{
  float a[25][25], k, d;

  k = 3;
  a[0][0] = 3; a[0][1] = 5; a[0][2] = 2;
  a[1][0] = 1; a[1][1] = 5; a[1][2] = 8;
  a[2][0] = 6.6; a[2][1] = 11; a[2][2] = 4.4;
  
  d = determinant(a, k);
  if (d == 0)
    printf("\nInverse of Entered Matrix is not possible\n");
  else
    cofactor(a, k);
}
 
/*For calculating Determinant of the Matrix */
float determinant(float a[25][25], float k)
{
  float s = 1, det = 0, b[25][25];
  int i, j, m, n, c;
  if (k == 1) {
    return (a[0][0]);
  } else {
    det = 0;
    for (c = 0; c < k; c++) {
      m = 0;
      n = 0;
      for (i = 0;i < k; i++) {
        for (j = 0 ;j < k; j++) {
          b[i][j] = 0;
          if (i != 0 && j != c) {
            b[m][n] = a[i][j];
            if (n < (k - 2))
              n++;
            else {
              n = 0;
              m++;
            }
          }
        }
      }
      det += s * (a[0][c] * determinant(b, k - 1));
      s *= -1;
    }
  }

  return (det);
}
 
void cofactor(float num[25][25], float f)
{
  float b[25][25], fac[25][25];
  int p, q, m, n, i, j;
  for (q = 0;q < f; q++) {
    for (p = 0;p < f; p++) {
      m = 0;
      n = 0;
      for (i = 0;i < f; i++) {
        for (j = 0;j < f; j++) {
          if (i != q && j != p) {
            b[m][n] = num[i][j];
            if (n < (f - 2))
              n++;
            else {
              n = 0;
              m++;
            }
          }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpose(num, fac, f);
}

/*Finding transpose of matrix*/ 
void transpose(float num[25][25], float fac[25][25], float r)
{
  int i, j;
  float b[25][25], inverse[25][25], d;
 
  for (i = 0;i < r; i++) {
    for (j = 0;j < r; j++) {
      b[i][j] = fac[j][i];
    }
  }

  d = determinant(num, r);
  
  for (i = 0;i < r; i++) {
    for (j = 0;j < r; j++) {
      inverse[i][j] = b[i][j] / d;
    }
  }
  
  printf("\n\n\nThe inverse of matrix is : \n");
 
  for (i = 0;i < r; i++) {
    for (j = 0;j < r; j++) {
      printf("\t%f", inverse[i][j]);
    }
    printf("\n");
  }
}
