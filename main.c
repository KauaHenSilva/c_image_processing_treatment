#include "imageRGB/imageRGB.c"
#include "imageGray/imageGray.c"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main()
{
  fileRGB = fopen("/home/user/dever_oseas/input_image.txt", "r");
  if (!fileRGB)
    perror("Não leu");

  fscanf(fileRGB, "%d", &alturaGlob);
  fscanf(fileRGB, "%d", &larguraGlob);

  Image *img = alocacaoImage(alturaGlob, larguraGlob);
  setPixel(alturaGlob, larguraGlob, img);

  printImage(img);

  // ImageGray *imgGray = converterParaCinza(img);
  // printImageGrey(imgGray);

  liberacaodeImage(img);
  return 0;
}
