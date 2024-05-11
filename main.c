#include "imageRGB/imageRGB.c"
#include "imageGray/imageGray.c"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef _WIN32
#include <unistd.h>
#endif

ImageGray *crusterizacao(ImageGray *imgGray)
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

  ImageGray *imgCrust = (ImageGray *)malloc(sizeof(ImageGray));
  imgCrust->altura = imgGray->altura;
  imgCrust->largura = imgGray->largura;
  imgCrust->pixel = (Pixelgray *)malloc(imgCrust->altura * imgCrust->largura * sizeof(Pixelgray));

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
        {
          imgCrust->pixel[i * larguraGlob + j].r = resultado;
          imgCrust->pixel[i * larguraGlob + j].g = resultado;
          imgCrust->pixel[i * larguraGlob + j].b = resultado;
        }
      }
  }

  fclose(seed);
  return imgCrust;
}

int main()
{
  fileRGB = fopen("/home/user/dever_oseas/input_image.txt", "r");
  if (!fileRGB)
#ifndef _WIN32
    perror("Não leu");
#else
    exit(EXIT_FAILURE);
#endif

  fscanf(fileRGB, "%d", &alturaGlob);
  fscanf(fileRGB, "%d", &larguraGlob);

  Image *img = alocacaoImage(alturaGlob, larguraGlob);
  setPixel(alturaGlob, larguraGlob, img);

  // printImage(img);

  ImageGray *imgGray = converterParaCinza(img);
  ImageGray *imgCrust = crusterizacao(imgGray);

  for (int i = 0; i < imgCrust->altura; i++)
  {
    for (int j = 0; j < imgCrust->largura; j++)
    {
      printf("%d", imgCrust->pixel[i * larguraGlob + j].r);
    }
    printf("\n");
  }

  // printImageGrey(imgGray);

  liberacaodeImage(img);
  liberacaodeImage(img);
  return 0;
}
