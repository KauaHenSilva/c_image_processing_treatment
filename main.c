#include "imageRGB/imageRGB.c"
#include "imageGray/imageGray.c"

#include <stdlib.h>
#include <stdio.h>

#ifndef _WIN32
#include <unistd.h>
#endif

int main()
{
  fileRGB = fopen("C:/meus_estudos_global/Desktop/C/3_periodo/dever_oseas/input_image.txt", "r");
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
  printImageGrey(imgGray);

  liberacaodeImage(img);
  liberacaodeImage(img);
  return 0;
}
