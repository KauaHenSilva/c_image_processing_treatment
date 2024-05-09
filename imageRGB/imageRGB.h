
typedef struct pixel PixelRGB;
typedef struct image Image;

// Printar as dimenções
void printDimensoesImage(Image *img);

// Mostrar os valores de um pixel expecifico dada as suas posições
void printPixel(int lin, int col, Image *img);

// retornar o pixel dado uma coluna e linha
PixelRGB getPixel(int lin, int col, Image *img);

// troca o valor de um pixel, dado as suas posicoes de linha e coluna
void setPixel(int lin, int col, Image *img);

// printa os pixel das imagem em forma de matrix
void printImage(Image *img);