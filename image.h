typedef struct pixel PixelRGB;
typedef struct image Imagem;

typedef struct pixelgray Pixelgray;
typedef struct image ImageGray;

// Mostrar a dimenções da imagem
void printDimensoeImage(Imagem *img);

// Mostrar os valores de um pixel expecifico dada as suas posições
void printPixel(int lin, int col, Imagem *img);

// retornar o pixel dado uma coluna e linha
PixelRGB getPixel(int lin, int col, Imagem *img);

// troca o valor de um pixel, dado as suas posicoes de linha e coluna
void setPixel(int lin, int col, Imagem *img);

// printa os pixel das imagem em forma de matrix
void printImage(Imagem *img);

