#include "PicProcess.h"

  // TODO: implement the PicProcess module

void invert_picture(struct picture *pic) {
  int width = get_image_width(pic->img);
  int height = get_image_height(pic->img);
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      struct pixel pixel = get_pixel(pic, i, j);
      int red = MAX_PIXEL_INTENSITY - pixel.red;
      int green = MAX_PIXEL_INTENSITY - pixel.green;
      int blue = MAX_PIXEL_INTENSITY - pixel.blue;
      struct pixel newPixel = {red, green, blue};
      set_pixel(pic, i, j, &newPixel);
    }
  }
}

void grayscale_picture(struct picture *pic) {
  int width = get_image_width(pic->img);
  int height = get_image_height(pic->img);
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      struct pixel pixel = get_pixel(pic, i, j);
      int avg = (pixel.red + pixel.green + pixel.blue) / 3;
      struct pixel newPixel = {avg, avg, avg};
      set_pixel(pic, i, j, &newPixel);
    }
  }
}

void rotate_picture(struct picture *pic, int angle) {
  for (int i = 0; i < angle / 90; i++) {
    for (int h = 0; h < pic->height; h++) {
      for (int w = 0; w < pic->width; w++) {
        struct pixel rgb = get_pixel(pic, w, h);
        set_pixel(pic, pic->height - 1 - h, w, &rgb);
      }
    }
  }
}

void flip_picture(struct picture *pic, char plane) {
  struct pixel rgb;
  if (plane == 'H') {
    for (int i = 0; i < pic->width; i++) {
      int w = pic->width - 1;
      for (int j = 0; j < pic->height; j++) {
        rgb = get_pixel(pic, i, j);
        set_pixel(pic, w - i, j, &rgb);
      }
    }
  } else if (plane == 'V') {
    for (int i = 0; i < pic->width; i++) {
      int h = pic->height - 1;
      for (int j = 0; j < pic->height; j++) {
        rgb = get_pixel(pic, i, j);
        set_pixel(pic, i, h - j, &rgb);
      }
    }
  }
}

void blur_picture(struct picture *pic) {
  int red = 0;
  int green = 0;
  int blue = 0;
  for (int j = 0; j < pic->height; j++) {
    for (int i = 0; i < pic->width; i++) {
      if (contains_point(pic, i + 1, j + 1) && contains_point(pic, i - 1, j - 1)) {
        for (int a = i - 1; a < i + 2; a++) {
          for (int b = j - 1; b < j + 2; b++) {
            struct pixel rgb = get_pixel(pic, a, b);
            red += rgb.red;
            blue += rgb.blue;
            green += rgb.green;
          }
        }
        struct pixel newPixel = {red / 9, green / 9, blue / 9};
        set_pixel(pic, i, j, &newPixel);
      }
    }
  }
}
