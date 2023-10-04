#include <stdio.h>
#include <string.h>
#include "Utils.h"
#include "Picture.h"
#include "PicProcess.h"

  // TODO: Implement the picture library package interface

  int main(int argc, char **argv){
      
    printf("------------------------------------------------------------\n");
    printf(" TODO: Implement the C Picture Processing Library Interface \n");
    printf("------------------------------------------------------------\n");

    // write main IO function to interface with the picture processing library

    sod_img image = load_image(argv[1]);
    struct picture picture = {image, get_image_width(image), get_image_height(image)};

    if (strcmp(argv[3], "invert") == 0) {
      invert_picture(&picture);
    } else if (strcmp(argv[3], "grayscale") == 0) {
      grayscale_picture(&picture);
    } else if (strcmp(argv[3], "rotate") == 0) {
      rotate_picture(&picture, atoi(argv[4]));
    } else if (strcmp(argv[3], "flip") == 0) {
      flip_picture(&picture, argv[4][0]);
    }



    return 0;
    
  } 


