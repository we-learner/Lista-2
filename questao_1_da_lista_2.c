#include <stdio.h>

int main()
{
  int array[10];
  int tamanho = 10;
  int i;

  for (i = 0; i < 10; i++)
  {
    scanf("%d", &array[i]);
  }

  for (i = 0; i < 10; i++)
  {
    printf("%d", array[i]);

    if (i < 9)
    {
      printf(" ");
    }
  }

  printf("\n");

  while (tamanho > 1)
  {
    for (i = 0; i < tamanho - 1; i++)
    {
      array[i] = array[i] + array[i + 1];
      printf("%d", array[i]);
      if (i < tamanho - 2)
      {
        printf(" ");
      }
    }

    tamanho--;

    printf("\n");
  }
  return 0;
}
