#include <iostream>
#include "CImg.h"
using namespace cimg_library;
using namespace std;

int main(int argc,char **argv) {
    // Read image filename from the command line (or set it to "lena.jpg" if option '-i' is not provided)
    const char* file_i = cimg_option("-i","/home/liantsoa/ensibs_vision/tp1/img/lena.jpg","Input image");
    // Load an image
    CImg<unsigned char> image = CImg<>(file_i);
    unsigned char purple[] = {255,0,255};// Define a purple color
    image.draw_text(10,10,"Hello World",purple);//Write text on image

    cout << "bruitage" << endl;
    CImg<unsigned char> image_noised = image.get_noise(10,2);
    cout << "variance noisee = " << image_noised.variance(0) << endl;
    cout << "variance_noise noisee = " << image_noised.variance_noise(0) << endl;
    cout << endl;
    
    CImg<unsigned char> img_median = image_noised;
    img_median.blur_median(5,0);
    cout << "variance blur_median = " << img_median.variance(0) << endl;
    cout << "variance_noise blur_median = " << img_median.variance_noise(0) << endl;
    cout << endl;

    CImg<unsigned char> img_box = image_noised;
    img_box.blur_box(5);
    cout << "variance blur_box = " << img_box.variance(0) << endl;
    cout << "variance_noise blur_box = " << img_box.variance_noise(0) << endl;
    cout << endl;

    CImg<unsigned char> img_aniso = image_noised;
    img_aniso.blur_anisotropic(100);
    cout << "variance blur_anisotropic = " << img_aniso.variance(0) << endl;
    cout << "variance_noise blur_anisotropic = " << img_aniso.variance_noise(0) << endl;   
    cout << endl;

    CImgDisplay disp(image,"OG");
    CImgDisplay disp_noised(image_noised,"noised");
    CImgDisplay disp_median(img_median,"blur_median");
    CImgDisplay disp_box(img_box,"blur_box");
    CImgDisplay disp_aniso(img_aniso,"blur_anisotropic");


    cin.get();

    return 0;
}
