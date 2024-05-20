/*
UNIVERSIDADE FEDERAL DO PIAUÍ
CURSO: SISTEMAS DE INFORMAÇÃO
MATÉRIA: ESTRUTURA DE DADOS I
DOCENTE: ANTONIO OSEAS DE CARVALHO FILHO
GRUPO:
CRISTINA DE MOURA SOUSA
FLAVIO LIMA MARTINS
KAUA HENRIQUE DA SILVA
WALISON WEUDES DE SOUSA E SILVA

The files in this folder are related to the assignment given by the professor through SIGAA,
entitled "Image". The code addresses topics such as file manipulation, manipulation of pixels
in RGB and GRAY, and clustering. The programming language chosen for this assignment is C.
*/

#include "imageRGB/imageRGB.h"
#include "imageGray/imageGray.h"
#include "imageCrust/imageCrust.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

int main()
{

  ImageRGB *img = alocacaoImage();
  setPixel(alturaGlob, larguraGlob, img);

  printImage(img);

  ImageGray *imgGray = converterParaCinza(img);

  printImageGrey(imgGray);

  ImageCrust *imgCrust = crusterizacao(imgGray);

  printImagemCrusterizada(imgCrust);

  liberacaodeImage(img);
  liberacaodeImageCrust(imgCrust);
  liberacaodeImageGray(imgGray);
  return 0;
}
