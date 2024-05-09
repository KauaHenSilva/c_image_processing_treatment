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
  int pixel;
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
  imagegray->pixel = (Pixelgray *)malloc(multAlturaLargura * sizeof(int));

  for (int x = 0; x < imagegray->altura; x++)
    for (int y = 0; y < imagegray->largura; y++)
    {
      int resultado;
      resultado = imagemrgb->pixel[x * larguraGlob + y].red;
      resultado += imagemrgb->pixel[x * larguraGlob + y].green;
      resultado += imagemrgb->pixel[x * larguraGlob + y].blue;
      resultado /= 3;
      imagegray->pixel[x * larguraGlob + y].pixel = resultado;
    }

  return imagegray;
}

void printPixelGray(int x, int y, ImageGray *img)
{
  int value = img->pixel[x * larguraGlob + y].pixel;
  printf("\033[48;5;%dm \033[0m", value);
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