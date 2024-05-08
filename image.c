#include "image.h"
#include "pixeis/exibirPixel.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct pixel
{
  int red, blue, green;
};

struct image
{
  int largura, altura;
  struct pixel *pixel;
};

struct image *alocacaoImage(int tamanho1, int tamanho2)
{
  struct image *image = (struct image *)malloc(sizeof(struct image));
  if (!image)
    perror("ERRO NA ALOCACAO DE MEMORIA DAS LINHAS DA MATRIZ.");

  image->altura = tamanho1;
  image->largura = tamanho2;

  image->pixel = (struct pixel*) malloc(sizeof(struct pixel) * tamanho1 * tamanho2);
  if (!image->pixel)
    perror("ERRO NA ALOCACAO DE MEMORIA DAS LINHAS DA MATRIZ.");

  return image;
}

void printImage(Imagem *img)
{
  for (int x = 0; x < img->largura; x++)
  {
    for (int y = 0; y < img->altura; y++)
    {
      exibirPixel(img->pixel[x * 10 + y].red, img->pixel[x * 10 + y].green, img->pixel[x * 10 + y].blue);
    }
    printf("\n");
  }
}

void liberacaodematriz(Imagem *img)
{
  free(img);
}

int main()
{
  int largura = 10;
  int altura = 10;

  struct image *img = alocacaoImage(largura, altura);

  for (int x = 0; x < 10; x++)
    for (int y = 0; y < 10; y++)
    {
      img->pixel[x * 10 + y].blue = rand() % 256;
      img->pixel[x * 10 + y].green = rand() % 256;
      img->pixel[x * 10 + y].red = rand() % 256;
    }

  printImage(img);

  return 0;
}
