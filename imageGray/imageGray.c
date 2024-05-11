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

void printImagemCrusterizada(ImageGray *imgCrust)
{
  for (int i = 0; i < imgCrust->altura; i++)
  {
    for (int j = 0; j < imgCrust->largura; j++)
      printf("%d%d", imgCrust->pixel[i * larguraGlob + j].r, imgCrust->pixel[i * larguraGlob + j].r);
    printf("\n");
  }
}

void liberacaodeImageGray(ImageGray *img)
{
  free(img->pixel);
  free(img);
}

#endif // IMAGEGRAY