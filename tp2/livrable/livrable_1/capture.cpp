#include <stdio.h>
#include <iostream>
#include <sstream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc, char** argv )
{
    VideoCapture cap(0);//pour capturer depuis la cam
    if ( !cap.isOpened())
    {
        cout << "Error retrieving frame \n";
        cout << "Could not open reference " << endl;
        return -1;
    }
    //force le flux MJPEG (moins de bande passante que le flux brut YUYV,
    //ce qui évite la corruption de trames via le pont USB/IP de WSL)
    cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M','J','P','G'));
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 480);

    TickMeter tm;
        while(true) //Boucle principale
    {
    Mat imgOriginal, imgGRAY, imgBIN;
    cap >> imgOriginal;//on capture une frame depuis le flux video
    if( imgOriginal.empty() )
    {
        cout << " < < < Frame Empty ! > > > ";
        break;
    }

    tm.start();//début de la mesure du temps de traitement de la frame
    cvtColor(imgOriginal, imgGRAY, cv::COLOR_RGB2GRAY);//Convert the image to gray levels
    threshold( imgGRAY, imgBIN, 128, 255, 0 );//threshold the gray image as to binarize it
    tm.stop();//fin de la mesure

    double frameTimeMs = tm.getTimeMilli();
    tm.reset();
    cout << "Temps de traitement de la frame : " << frameTimeMs << " ms" << endl;

    std::ostringstream oss;
    oss << "frame: " << frameTimeMs << " ms";
    putText(imgOriginal, oss.str(), Point(10,20), FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255,0,0), 2, 8, false);

    //show the images
    imshow("couleurs", imgOriginal); //show the original image
    imshow("niveaux de gris",imgGRAY);
    imshow("binaire", imgBIN);
    if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
    {
        cout << "ESC key pressed by user - video thread terminates" << endl;
        break;
    }
    }//fin du while boucle principale
    return 0;
}