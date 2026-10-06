#include <iostream>
#include "CImg.h"
using namespace cimg_library;

int main(int argc,char **argv) {
    // Read image filename from the command line (or set it to "lena.jpg" if option '-i' is not provided)
    const char* file_i = cimg_option("-i","/home/liantsoa/ensibs_vision/tp1/img/lena.jpg","Input image");
    // Load an image
    CImg<unsigned char> image = CImg<>(file_i);
    unsigned char purple[] = {255,0,255};// Define a purple color
    image.draw_text(10,10,"Hello World",purple);//Write text on image
    image.display("lena");//Display image
    return 0;
}
