typedef struct pixelgray Pixelgray;
typedef struct imageGray ImageGray;

typedef struct imageCrust ImageCrust;

void printImagemCrusterizada(ImageCrust *imgCrust);
ImageCrust *crusterizacao(ImageGray *imgGray);
void liberacaodeImageCrust(ImageCrust *img);