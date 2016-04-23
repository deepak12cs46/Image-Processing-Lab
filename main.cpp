#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "collectfunc.h"
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
if (argc!=2)
	{
	printf( " usage: DisplayImage.out <Image_Path>\n" );
	return - 1;
	}
	Mat image;
	image = imread( argv[1], 1 );
	if ( ! image.data )
	{
	printf( " No image data \n" );
	return 0;
	}
cout<<"Displaying image "<<endl;
displayimage("displayimage",image);
cout<<"converting in gray scale"<<endl;
Mat grayimage=convertingrayimage(argv);
cout<<"min filter"<<endl;
findminfilter(grayimage);
cout<<"max filter"<<endl;
findmaxfilter(grayimage);
cout<<"conv2 function"<<endl;
conv2(grayimage, 11);
cout<<"median filter"<<endl;
medianfilter(grayimage);
cout<<"log and power law transformations"<<endl;
transformations(grayimage);
cout<<"histogram equalization"<<endl;
histogramequalization(grayimage);
cout<<"histograms "<<endl;
histograms(grayimage);
return 0;
}
