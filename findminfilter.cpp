#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "highgui.h"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

#include "collectfunc.h"
void findminfilter(Mat src)
{	Mat result,element;
	erode( src, result,element);
	displayimage("findminfilter",result);
}
