#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "collectfunc.h"
using namespace cv;
void displayimage(char *name,Mat image)
{

	namedWindow( name , CV_WINDOW_AUTOSIZE );
	imshow( name , image);
	waitKey( 0);

}
