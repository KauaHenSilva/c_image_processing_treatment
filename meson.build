project('project Img', 'c')

subdir('src/imageStructAndGlobVar')
subdir('src/imageGray')
subdir('src/imageRGB')
subdir('src/imageCrust')

executable(
  'main',
  'src/main.c',
  link_with: [image_rgb, image_gray, image_crust, image_struct_and_glob_var],
)

configure_file(input: 'input_image.txt', output: 'input_image.txt', copy: true)