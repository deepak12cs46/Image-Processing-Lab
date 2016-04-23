#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;
#include "collectfunc.h"
void medianfilter(Mat src)
{
	Mat dst;
for ( int i = 1; i < 11; i = i + 2 )
    {
	medianBlur ( src, dst, i );
    }
displayimage("medianfilter",dst);
}
