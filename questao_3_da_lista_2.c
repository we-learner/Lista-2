#include <stdio.h>
#include <string.h>

#define N 4

void ler_matriz(int matriz[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      scanf("%d", &matriz[i][j]);
    }
  }
}

void imprimir_matriz(int matriz[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%4d", matriz[i][j]);
    }
    printf("\n");
  }
}

void somar_matrizes(int A[N][N], int B[N][N], int C[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}

void subtrair_matrizes(int A[N][N], int B[N][N], int C[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      C[i][j] = A[i][j] - B[i][j];
    }
  }
}

void multiplicar_matrizes(int A[N][N], int B[N][N], int C[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      C[i][j] = 0;
      for (int k = 0; k < N; k++)
      {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

int main()
{
  int A[N][N], B[N][N], C[N][N];

  ler_matriz(A);
  ler_matriz(B);

  char operacao[10];
  scanf("%s", operacao);

  if (strcmp(operacao, "soma") == 0)
  {
    somar_matrizes(A, B, C);
  } else if (strcmp(operacao, "sub") == 0)
  {
    subtrair_matrizes(A, B, C);
  } else if (strcmp(operacao, "mult") == 0)
  {
    multiplicar_matrizes(A, B, C);
  } else
  {
    printf("Operação inválida.\n");
    return 1;
  }

  imprimir_matriz(C);

  return 0;
}