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

void printDimensoeImage(Imagem *img)
{
  printf("A largura e: %d", img->largura);
  printf("A altura e: %d", img->altura);
}

void printPixel(int lin, int col, Imagem *img)
{

  int r, g, b;
  r = img->pixel[lin * LARGURA + col].red;
  g = img->pixel[lin * LARGURA + col].green;
  b = img->pixel[lin * LARGURA + col].blue;

  if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
    perror("Valores RGB fora do intervalo permitido.\n");

  printf("\033[38;2;%d;%d;%dm*\033[0m", r, g, b);
}

PixelRGB getPixel(int lin, int col, Imagem *img)
{
  return img->pixel[lin * LARGURA + col];
}

void setPixel(int lin, int col, Imagem *img)
{
  for (int x = 0; x < lin; x++)
    for (int y = 0; y < col; y++)
    {
      img->pixel[x * LARGURA + y].blue = rand() % 256;
      img->pixel[x * LARGURA + y].green = rand() % 256;
      img->pixel[x * LARGURA + y].red = rand() % 256;
    }
}

Imagem *alocacaoImage(int lin, int col)
{
  Imagem *image = (Imagem *)malloc(sizeof(Imagem));
  if (!image)
    perror("ERRO NA ALOCACAO DE MEMORIA DAS LINHAS DA MATRIZ.");

  image->altura = lin;
  image->largura = col;

  image->pixel = (PixelRGB *)malloc(sizeof(PixelRGB) * lin * col);
  if (!image->pixel)
    perror("ERRO NA ALOCACAO DE MEMORIA DAS LINHAS DA MATRIZ.");

  return image;
}

void printImage(Imagem *img)
{
  for (int x = 0; x < img->largura; x++)
  {
    for (int y = 0; y < img->altura; y++)
      printPixel(x, y, img);
    printf("\n");
  }
}

void liberacaodematriz(Imagem *img)
{
  free(img);
}

int main()
{
  int largura = LARGURA;
  int altura = ALTURA;

  Imagem *img = alocacaoImage(largura, altura);
  setPixel(largura, altura, img);
  printImage(img);

  return 0;
}
