#include "exibirPixel.h"

void exibirPixel(int r, int g, int b)
{
  if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
  {
    printf("Valores RGB fora do intervalo permitido.\n");
    return;
  }
  printf("\033[38;2;%d;%d;%dm*\033[0m\n", r, g, b);
}