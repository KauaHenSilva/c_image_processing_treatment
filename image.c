#include "image.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define LARGURA 10
#define ALTURA 10

struct pixel
{
  int red, blue, green;
};

struct image
{
  int largura, altura;
  PixelRGB *pixel;
};

struct pixelgray
{
  int gray;
};

void printDimensoeImage(Imagem *img)
{
  printf("A largura e: %d", img->largura);
  printf("A altura e: %d", img->altura);
}

void printPixel(int R, int G, int B)
{
  int r, g, b;

  r = R;
  g = G;
  b = B;

  if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
    perror("Valores RGB fora do intervalo permitido.\n");

  printf("\033[38;2;%d;%d;%dm*\033[0m", r, g, b);
}

void liberacaodematriz(Imagem *img)
{
  free(img);
}

int main()
{
  int largura;
  int altura;
  FILE *open = fopen("C:\\Users\\flavi\\Downloads\\image\\input_image.txt", "r+");
  if (open == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }
  if (fscanf(open, "%d\n", &largura) == 1)
  {
  }
  if (fscanf(open, "%d\n", &altura) == 2)
  {
  }

  int r, g, b;
  system("PAUSE");
  while (fscanf(open, "%d %d %d,", &r, &g, &b) != '\0')
  {
    printPixel(r, g, b);
  }

  fclose(open);

  return 0;
}
