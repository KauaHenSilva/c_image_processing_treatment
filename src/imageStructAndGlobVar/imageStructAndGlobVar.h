#pragma once

/**
 * @brief Structure representing a pixel in RGB format.
 */
typedef struct pixel
{
  int red;    /**< The red component of the pixel. */
  int blue;   /**< The blue component of the pixel. */
  int green;  /**< The green component of the pixel. */
} PixelRGB;

/**
 * @brief Structure representing an RGB image.
 */
typedef struct imageRGB
{
  int largura;      /**< The width of the image. */
  int altura;       /**< The height of the image. */
  PixelRGB *pixel;  /**< Pointer to the pixel data of the image. */
} ImageRGB;


/**
 * @brief Structure representing an gray image.
 */
typedef struct imageGray
{
	int largura, altura;
	int *pixel;
} ImageGray;


/**
 * @struct imageCrust
 * @brief Represents the structure for image crust.
 * 
 * This structure is used to store information about the crust of an image.
 * It can be used to access and manipulate the crust data of an image.
 */
typedef struct imageCrust
{
  int largura, altura;
  int *pixel;
} ImageCrust;

/**
 * @brief The global variable representing the width of the image.
 */
extern int larguraGlob;

/**
 * @brief The global variable representing the height of the image.
 */
extern int alturaGlob;
