#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include<cv.h>
#include "collectfunc.h"

using namespace cv;
using namespace std;


Mat conv2(Mat src, int kernel_size)
{
	Mat dst;
	//apply filter
	boxFilter(src, dst, -1, Size(kernel_size, kernel_size), Point(-1, -1), true, BORDER_DEFAULT);
	displayimage("averagefilter",dst);
	return dst;
}
