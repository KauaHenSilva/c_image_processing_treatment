
#include <stdlib.h>
#include <stdio.h>

#include "imageGray.h"

ImageGray *converterParaCinza(ImageRGB *imagemrgb)
{
  ImageGray *imagegray = (ImageGray *)malloc(sizeof(ImageGray));
  imagegray->altura = imagemrgb->altura;
  imagegray->largura = imagemrgb->largura;

  int multAlturaLargura = imagegray->altura * imagegray->largura;
  imagegray->pixel = (int *)malloc(multAlturaLargura * sizeof(int));

  for (int x = 0; x < imagegray->altura; x++)
    for (int y = 0; y < imagegray->largura; y++)
    {
      int resultado;
      resultado = imagemrgb->pixel[x * larguraGlob + y].red;
      resultado += imagemrgb->pixel[x * larguraGlob + y].green;
      resultado += imagemrgb->pixel[x * larguraGlob + y].blue;

      resultado /= 3;

      imagegray->pixel[x * larguraGlob + y] = resultado;
    }

  return imagegray;
}

void printPixelGray(int lin, int col, ImageGray *img)
{
  int gray;
  gray = img->pixel[lin * larguraGlob + col];

  if (gray < 0 || gray > 255)
    perror("Valores RGB fora do intervalo permitido.\n");

  printf("\033[38;2;%d;%d;%dm**\033[0m", gray, gray, gray);
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

void liberacaodeImageGray(ImageGray *img)
{
  free(img->pixel);
  free(img);
}
