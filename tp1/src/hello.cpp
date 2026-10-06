#include <iostream>
#include "CImg.h"
using namespace cimg_library;
using namespace std;

//================================================
//functions prototypes

//rgb2gray : the input is a RGB image, the ouput is a graylevel image
//a pixel gray level is the mean of its R,G and B values
CImg<unsigned char> rgb2gray(CImg<unsigned char>);

//rgb2grayw : the input is a RGB image, the ouput is a graylevel image
//a pixel gray level is a combination ot its R,G, and B values such as
//graylevel=(0.299*R + 0.587*G + 0.114*B);
CImg<unsigned char> rgb2grayw(CImg<unsigned char>);

//================================================
//functions

//*******************************************************************
//rgb2gray : the input is a RGB image, the ouput is a graylevel image
CImg<unsigned char> rgb2gray(CImg<unsigned char> prem)
{
    CImg<unsigned char> gray(prem.width(), prem.height(), 1, 1, 0);
    // for all pixels x,y in image
    cimg_forXY(prem,x,y) {
        // Separation of channels
        int R = (int)prem(x,y,0,0);
        int G = (int)prem(x,y,0,1);
        int B = (int)prem(x,y,0,2);
        // Arithmetic addition of channels for gray
        int grayValue = (int)(0.33*R + 0.33*G + 0.33*B);
        // Real weighted addition of channels for gray
        //int grayValueWeight = (int)(0.299*R + 0.587*G + 0.114*B);
        // saving píxel values into image information
        gray(x,y,0,0) = grayValue;
        //grayWeight(x,y,0,0) = grayValueWeight;
    }
    return gray;
}
//*******************************************************************


//********************************************************************
//rgb2grayw : the input is a RGB image, the ouput is a graylevel image
CImg<unsigned char> rgb2grayw(CImg<unsigned char> prem)
{
    CImg<unsigned char> gray(prem.width(), prem.height(), 1, 1, 0);
    // for all pixels x,y in image
    cimg_forXY(prem,x,y) {
        // Separation of channels
        int R = (int)prem(x,y,0,0);
        int G = (int)prem(x,y,0,1);
        int B = (int)prem(x,y,0,2);
        // Arithmetic addition of channels for gray
        //int grayValue = (int)(0.33*R + 0.33*G + 0.33*B);
        // Real weighted addition of channels for gray
        int grayValue = (int)(0.299*R + 0.587*G + 0.114*B);
        // saving píxel values into image information
        gray(x,y,0,0) = grayValue;
        //grayWeight(x,y,0,0) = grayValueWeight;
    }
    return gray;
}
//********************************************************************

int main(int argc,char **argv) {
    // Read image filename from the command line (or set it to "lena.jpg" if option '-i' is not provided)
    const char* file_i = cimg_option("-i","/home/liantsoa/ensibs_vision/tp1/img/lena.jpg","Input image");
    // Load an image
    CImg<unsigned char> image = CImg<>(file_i);

    // LIVRABLE 4 : transformer l'image en niveaux de gris avec les deux variantes
    CImg<unsigned char> grayimg = rgb2gray(image);
    CImg<unsigned char> grayimgw = rgb2grayw(image);

    // Affichage de l'image en niveaux de gris (exemple du sujet)
    CImgDisplay disp(grayimg,"display");
    grayimg.display(disp);//affichage de l'image en niveaux de gris

    CImgDisplay dispw(grayimgw,"display");
    grayimgw.display(dispw);//affichage de l'image en niveaux de gris

    //méthode 3, avec draw_graph à partir de la classe CImg
    CImg<unsigned char> visu(500,400,1,3,0);//on construit l'image
    CImgDisplay draw_disp(visu,"histogramme");//on construit son display et on l'affiche
    const unsigned char red[] = { 255,0,0 };//on définit une couleur
    visu.fill(0).draw_graph(grayimg.get_histogram(256).normalize(0,255),red,1,3,0,255,0).display(draw_disp);//ICI on n'écrase pas "grayimg", il faut cependant normaliser les valeurs retournées par "get_histogram"

    CImg<unsigned char> visuw(500,400,1,3,0);//on construit l'image
    CImgDisplay draw_dispw(visuw,"histogramme");//on construit son display et on l'affiche
    visuw.fill(0).draw_graph(grayimgw.get_histogram(256).normalize(0,255),red,1,3,0,255,0).display(draw_dispw);//ICI on n'écrase pas "grayimgw", il faut cependant normaliser les valeurs retournées par "get_histogram"

    cin.get();

    return 0;
}
