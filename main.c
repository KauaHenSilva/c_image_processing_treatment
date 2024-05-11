#include "imageRGB/imageRGB.c"
#include "imageGray/imageGray.c"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef _WIN32
#include <unistd.h>
#endif

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

  // printImageGrey(imgGray);

  ImageGray *imgCrust = crusterizacao(imgGray);

  printImagemCrusterizada(imgCrust);

  liberacaodeImage(img);
  liberacaodeImageGray(imgCrust);
  liberacaodeImageGray(imgGray);
  return 0;
}
