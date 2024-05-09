#include "image.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define LARGURA 10
#define ALTURA 10

struct pixel
{
  int red, blue, green;
};

struct image
{
  int largura, altura;
  PixelRGB *pixel;
};

struct pixelgray
{
  int gray;
};

void printPixel(int R, int G, int B) {
    int r, g, b;
    double gray;

    r = R;
    g = G;
    b = B;

    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        perror("Valores RGB fora do intervalo permitido.\n");
        return;
    }

    gray = 0.2126 * r + 0.7152 * g + 0.0722 * b;

    printf("\033[38;2;%d;%d;%dm00\033[0m", (int)gray, (int)gray, (int)gray);
}


void liberacaodematriz(Imagem *img)
{
  free(img);
}

int main()
{
  int largura;
  int altura;
  FILE *open = fopen("C:\\Users\\flavi\\Downloads\\image\\input_image.txt", "r+");
  if (open == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }
  if (fscanf(open, "%d\n", &largura) == 1)
  {
  }
  if (fscanf(open, "%d\n", &altura) == 2)
  {
  }

  int r, g, b;
  system("PAUSE");
  for (int i = 0; i < largura; i++)
  {
    
    for (int j = 0; j < altura; j++)
    {
      fscanf(open, "%d %d %d,", &r, &g, &b);
      fgetc(open);

      printPixel(r, g, b);
    }
    printf("\n");
  }

  fclose(open);

  return 0;
}
