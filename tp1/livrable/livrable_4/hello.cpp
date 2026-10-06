#include <iostream>
#include "CImg.h"
using namespace cimg_library;
using namespace std;

// rgb2gray : niveau de gris = moyenne arithmetique simple des 3 canaux
CImg<unsigned char> rgb2gray(CImg<unsigned char> prem) {
    CImg<unsigned char> gray(prem.width(), prem.height(), 1, 1, 0);
    cimg_forXY(prem,x,y) {
        int R = (int)prem(x,y,0,0);
        int G = (int)prem(x,y,0,1);
        int B = (int)prem(x,y,0,2);
        int grayValue = (int)(0.33*R + 0.33*G + 0.33*B);
        gray(x,y,0,0) = grayValue;
    }
    return gray;
}

// rgb2grayw : niveau de gris = combinaison ponderee (perception humaine : 0.299R + 0.587G + 0.114B)
CImg<unsigned char> rgb2grayw(CImg<unsigned char> prem) {
    CImg<unsigned char> gray(prem.width(), prem.height(), 1, 1, 0);
    cimg_forXY(prem,x,y) {
        int R = (int)prem(x,y,0,0);
        int G = (int)prem(x,y,0,1);
        int B = (int)prem(x,y,0,2);
        int grayValue = (int)(0.299*R + 0.587*G + 0.114*B);
        gray(x,y,0,0) = grayValue;
    }
    return gray;
}

int main(int argc,char **argv) {
    const char* file_i = cimg_option("-i","/home/liantsoa/ensibs_vision/tp1/img/lena.jpg","Input image");
    CImg<unsigned char> image = CImg<>(file_i);

    // Conversion en niveaux de gris avec les deux variantes
    CImg<unsigned char> gray_mean = rgb2gray(image);
    CImg<unsigned char> gray_weighted = rgb2grayw(image);

    // Affichage des deux images en niveaux de gris
    CImgDisplay disp_mean(gray_mean,"gris - moyenne arithmetique");
    CImgDisplay disp_weighted(gray_weighted,"gris - moyenne ponderee");

    // Affichage de leur histogramme respectif (methode 3, draw_graph, sans ecraser les images)
    const unsigned char red[] = { 255,0,0 };

    CImg<unsigned char> visu_mean(500,400,1,3,0);
    CImgDisplay disp_hist_mean(visu_mean,"histogramme - moyenne arithmetique");
    visu_mean.fill(0).draw_graph(gray_mean.get_histogram(256).normalize(0,255),red,1,3,0,255,0).display(disp_hist_mean);

    CImg<unsigned char> visu_weighted(500,400,1,3,0);
    CImgDisplay disp_hist_weighted(visu_weighted,"histogramme - moyenne ponderee");
    visu_weighted.fill(0).draw_graph(gray_weighted.get_histogram(256).normalize(0,255),red,1,3,0,255,0).display(disp_hist_weighted);

    cin.get();

    return 0;
}
