#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include "collectfunc.h"
using namespace cv;
using namespace std;
void histogramequalization(Mat src)
{
	Mat dst;
	equalizeHist( src, dst );
	displayimage("histogram equalization",dst);
}
