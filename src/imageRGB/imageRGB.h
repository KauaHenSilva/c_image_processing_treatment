#include <stdio.h>

#include "../imageStructAndGlobVar/imageStructAndGlobVar.h"

/**
 * @brief External file pointer for RGB image file.
 * 
 * This variable represents an external file pointer for the RGB image file.
 * It is used to read or write data from/to the RGB image file.
 */
extern FILE *fileRGB;

/**
 * Allocates memory for an ImageRGB object.
 *
 * @return A pointer to the allocated ImageRGB object.
 */
ImageRGB *alocacaoImage();

/**
 * Prints the dimensions of the given ImageRGB.
 *
 * @param img The ImageRGB object whose dimensions are to be printed.
 */
void printDimensoesImage(ImageRGB *img);

/**
 * Prints the pixel at the specified coordinates in the given ImageRGB object.
 *
 * @param lin The line number of the pixel.
 * @param col The column number of the pixel.
 * @param img A pointer to the ImageRGB object.
 */
void printPixel(int lin, int col, ImageRGB *img);

// retornar o pixel dado uma coluna e linha
/**
 * Retrieves the pixel at the specified position in the image.
 *
 * @param lin The line number of the pixel.
 * @param col The column number of the pixel.
 * @param img A pointer to the ImageRGB structure.
 * @return The PixelRGB structure representing the pixel at the specified position.
 */
PixelRGB getPixel(int lin, int col, ImageRGB *img);

// troca o valor de um pixel, dado as suas posicoes de linha e coluna
/**
 * Sets the pixel at the specified coordinates in the given ImageRGB object.
 *
 * @param lin The line number of the pixel.
 * @param col The column number of the pixel.
 * @param img A pointer to the ImageRGB object.
 */
void setPixel(int lin, int col, ImageRGB *img);

// printa os pixel das imagem em forma de matrix
/**
 * Prints the given ImageRGB object.
 *
 * @param img The ImageRGB object to be printed.
 */
void printImage(ImageRGB *img);

/**
 * @brief Frees the memory allocated for an ImageRGB object.
 *
 * This function releases the memory allocated for the given ImageRGB object.
 *
 * @param img Pointer to the ImageRGB object to be freed.
 */
void liberacaodeImage(ImageRGB *img);
