#if !defined(IMAGEGRAY)
#define IMAGEGRAY

#include "imageGray.h"
#include "../imageRGB/imageRGB.c"

#ifndef TAMANHOIMAGEM
#define TAMANHOIMAGEM
int larguraGlob;
int alturaGlob;
#endif

struct pixelgray
{
  int r;
  int g;
  int b;
};

struct imageGray
{
  int largura, altura;
  Pixelgray *pixel;
};

ImageGray *converterParaCinza(Image *imagemrgb)
{
  ImageGray *imagegray = (ImageGray *)malloc(sizeof(ImageGray));
  imagegray->altura = imagemrgb->altura;
  imagegray->largura = imagemrgb->largura;

  int multAlturaLargura = imagegray->altura * imagegray->largura;
  imagegray->pixel = (Pixelgray *)malloc(multAlturaLargura * sizeof(Pixelgray));

  for (int x = 0; x < imagegray->altura; x++)
    for (int y = 0; y < imagegray->largura; y++)
    {
      int resultado;
      resultado = imagemrgb->pixel[x * larguraGlob + y].red;
      resultado += imagemrgb->pixel[x * larguraGlob + y].green;
      resultado += imagemrgb->pixel[x * larguraGlob + y].blue;

      resultado /= 3;

      imagegray->pixel[x * larguraGlob + y].r = resultado;
      imagegray->pixel[x * larguraGlob + y].g = resultado;
      imagegray->pixel[x * larguraGlob + y].b = resultado;
    }

  return imagegray;
}

void printPixelGray(int lin, int col, ImageGray *img)
{
  int r, g, b;
  r = img->pixel[lin * larguraGlob + col].r;
  g = img->pixel[lin * larguraGlob + col].g;
  b = img->pixel[lin * larguraGlob + col].b;

  if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
    perror("Valores RGB fora do intervalo permitido.\n");

  printf("\033[38;2;%d;%d;%dm*\033[0m", r, g, b);
}

void printImageGrey(ImageGray *img)
{
  for (int x = 0; x < img->largura; x++)
  {
    for (int y = 0; y < img->altura; y++)
      printPixelGray(x, y, img);
    printf("\n");
  }
}

#endif // IMAGEGRAY