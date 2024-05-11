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

Os arquivos nesta pasta estão relacionados ao
trabalho designado pelo professor através do SIGAA,
intitulado "Image". O código aborda temas como
manipulação de arquivos, manipulação de pixels
em RGB e GRAY e clusterização. A linguagem de
programação escolhida para este trabalho é C.
*/

#include "imageRGB/imageRGB.c"
#include "imageGray/imageGray.c"
#include "imageCrust/imageCrust.c"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef _WIN32
#include <unistd.h>
#endif

int main()
{

  Image *img = alocacaoImage();
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
