#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_japan_flag(gdImagePtr img);
void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int white, int red );

int main() {
    // width 3: height 2
    int width = 1200;
    int height = 2 * width / 3;

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_japan_flag(img);

    FILE *outputFile = fopen("./../images/japan_flag.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);
    return 0;
}

void draw_japan_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, white ;
    int center_x =  0.5 * width;
    int center_y =  0.5 * height;
    int sun_radius = 145 ;

    // Colors for the flag
    red = gdImageColorAllocate(img, 242, 0, 0); // Red color
    white = gdImageColorAllocate(img, 255, 255, 255); // White stripes


    // 繪製白色矩形區域
    gdImageFilledRectangle(img, 0, 0, width, height, white);


    // 繪製太陽內部
    gdImageFilledEllipse(img, center_x, center_y, sun_radius * 3, sun_radius * 3, red);
}
