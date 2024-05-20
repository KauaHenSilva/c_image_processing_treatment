#include "../imageStructAndGlobVar/imageStructAndGlobVar.h"

/**
 * Converts an RGB image to grayscale.
 *
 * @param imagemrgb The RGB image to be converted.
 * @return The grayscale image.
 */
ImageGray *converterParaCinza(ImageRGB *imagemrgb);

/**
 * Prints the grayscale value of a pixel at the specified coordinates.
 *
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param img The grayscale image.
 */
void printPixelGray(int x, int y, ImageGray *img);

/**
 * Prints the grayscale values of all pixels in the image.
 *
 * @param img The grayscale image.
 */
void printImageGrey(ImageGray *img);

/**
 * Frees the memory allocated for the grayscale image.
 *
 * @param img The grayscale image to be freed.
 */
void liberacaodeImageGray(ImageGray *img);
