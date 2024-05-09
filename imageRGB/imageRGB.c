
#if !defined(IMAGERGB)
#define IMAGERGB

#include "imageRGB.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef TAMANHOIMAGEM
#define TAMANHOIMAGEM
int larguraGlob;
int alturaGlob;
#endif

FILE *fileRGB;

struct pixel
{
  int red, blue, green;
};

struct image
{
  int largura, altura;
  PixelRGB *pixel;
};

void printDimensoeImage(Image *img)
{
  printf("A largura e: %d", img->largura);
  printf("A altura e: %d", img->altura);
}

void printPixel(int lin, int col, Image *img)
{
  int r, g, b;
  r = img->pixel[lin * larguraGlob + col].red;
  g = img->pixel[lin * larguraGlob + col].green;
  b = img->pixel[lin * larguraGlob + col].blue;

  if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
    perror("Valores RGB fora do intervalo permitido.\n");

  printf("\033[38;2;%d;%d;%dm*\033[0m", r, g, b);
}

PixelRGB getPixel(int lin, int col, Image *img)
{
  return img->pixel[lin * larguraGlob + col];
}

void setPixel(int lin, int col, Image *img)
{
  for (int x = 0; x < lin; x++)
    for (int y = 0; y < col; y++)
    {
      fscanf(fileRGB, "%d", &img->pixel[x * larguraGlob + y].red);
      fscanf(fileRGB, "%d", &img->pixel[x * larguraGlob + y].green);
      fscanf(fileRGB, "%d", &img->pixel[x * larguraGlob + y].blue);
      fgetc(fileRGB);
    }
}

Image *alocacaoImage(int lin, int col)
{
  Image *image = (Image *)malloc(sizeof(Image));
  if (!image)
    perror("ERRO NA ALOCACAO DE MEMORIA DAS LINHAS DA MATRIZ.");

  image->altura = lin;
  image->largura = col;

  image->pixel = (PixelRGB *)malloc(sizeof(PixelRGB) * lin * col);
  if (!image->pixel)
    perror("ERRO NA ALOCACAO DE MEMORIA DAS LINHAS DA MATRIZ.");

  return image;
}

void printImage(Image *img)
{
  for (int x = 0; x < img->largura; x++)
  {
    for (int y = 0; y < img->altura; y++)
      printPixel(x, y, img);
    printf("\n");
  }
}

void liberacaodeImage(Image *img)
{
  free(img);
}

#endif