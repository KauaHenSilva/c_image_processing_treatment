typedef struct pixel PixelRGB;
typedef struct image Image;

// nova
typedef struct pixelgray Pixelgray;
typedef struct imageGray ImageGray;
/*
Novas funcoes
- ler txt e converter em imagem -> Image
- exportar imagem para txt -> txt salvo
- Converter imagem RGB para nivel de cinza, isto é, com um único valor de pixel -> ImageGray
- aplicar clusterizacao na imagem a partir de um arquivo txt com sementes,
	adtaptar a funcao da distancia euclidiana para considerar apenas os valores do pixel -> salvar txt com o resultado da clusterizacao
*/

ImageGray *converterParaCinza(Image *imagemrgb);
void printPixelGray(int x, int y, ImageGray *img);
void printPixelGray(int x, int y, ImageGray *img);
void printImageGrey(ImageGray *img);
void printImagemCrusterizada(ImageGray *imgCrust);
ImageGray *crusterizacao(ImageGray *imgGray);
