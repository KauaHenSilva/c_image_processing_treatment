#include "imageCrust.h"
#include "../imageGray/imageGray.c"
#include <stdlib.h>
#include <stdio.h>

#ifndef TAMANHOIMAGEM
#define TAMANHOIMAGEM
int larguraGlob;
int alturaGlob;
#endif


struct imageCrust
{
  int largura, altura;
  int *pixel;
};

void printImagemCrusterizada(ImageCrust *imgCrust)
{
  for (int i = 0; i < imgCrust->altura; i++)
  {
    for (int j = 0; j < imgCrust->largura; j++)
      printf("%d%d", imgCrust->pixel[i * larguraGlob + j], imgCrust->pixel[i * larguraGlob + j]);
    printf("\n");
  }
}

ImageCrust *crusterizacao(ImageGray *imgGray)
{
  FILE *seed = fopen("/home/user/dever_oseas/seed.txt", "r");
  if (!seed)
#ifndef _WIN32
    perror("Não leu");
#else
    exit(EXIT_FAILURE);
#endif

  // X   Y   DIFERENCA
  // 310 290 30
  // 121 65 20
  // 199 393 20
  // 218 91 30
  // 287 159 30

  ImageCrust *imgCrust = (ImageCrust *)malloc(sizeof(ImageCrust));
  imgCrust->altura = imgGray->altura;
  imgCrust->largura = imgGray->largura;
  imgCrust->pixel = (int *)malloc(imgCrust->altura * imgCrust->largura * sizeof(int));

  int x, y, diferenca, pixelAtual;
  int resultado;
  while (fscanf(seed, "%d %d %d %d", &x, &y, &diferenca, &resultado) != EOF)
  {
    int pCinza = imgGray->pixel[x * larguraGlob + y].r;
    for (int i = 0; i < imgGray->altura; i++)
      for (int j = 0; j < imgGray->largura; j++)
      {
        pixelAtual = imgGray->pixel[i * larguraGlob + j].r;

        int diferencaAtual = pCinza - pixelAtual;
        if (diferencaAtual < 0)
          diferencaAtual *= -1;

        if (diferencaAtual <= diferenca)
          imgCrust->pixel[i * larguraGlob + j] = resultado;
      }
  }

  fclose(seed);
  return imgCrust;
}

void liberacaodeImageCrust(ImageCrust *img)
{
  free(img->pixel);
  free(img);
}
