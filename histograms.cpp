#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "collectfunc.h"
/*
Given an RGB image,
do :
Create three 1D arrays for holding the red, green, and blue histogram.
For each channel, count the number of pixels for each tonal value.
Create three canvas for drawing the histogram. To make things simple,
set the width = 256 and the height = 125.
Normalize the histogram value to 0-125.
For each histogram, draw lines on the canvas to represent the histogram value.
Display all canvas.
The arrays will be stored in std::vector container. And as you will see later, it will make the algorithm also works for single-channel image.
*/

using namespace cv;
using namespace std;

void showHistogram(Mat& img)
{
	int bins = 256;             // number of bins
	int nc = img.channels();    // number of channels

	vector<Mat> hist(nc);       // histogram arrays
	cout<<"inside histogram1"<<endl;
	// Initalize histogram arrays
	for (int i = 0; i < hist.size(); i++)
		hist[i] = Mat::zeros(1, bins, CV_32SC1);
	cout<<"inside histogram2"<<endl;
	// Calculate the histogram of the image
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			for (int k = 0; k < nc; k++)
			{
				uchar val = nc == 1 ? img.at<uchar>(i,j) : img.at<Vec3b>(i,j)[k];
				hist[k].at<int>(val) += 1;
			}
		}
	}

	// For each histogram arrays, obtain the maximum (peak) value
	// Needed to normalize the display later
	int hmax[3] = {0,0,0};
	cout<<"inside histogram3"<<endl;
	for (int i = 0; i < nc; i++)
	{
		for (int j = 0; j < bins-1; j++)
			hmax[i] = hist[i].at<int>(j) > hmax[i] ? hist[i].at<int>(j) : hmax[i];
	}

	const char* wname[3] = { "blue", "green", "red" };
	Scalar colors[3] = { Scalar(255,0,0), Scalar(0,255,0), Scalar(0,0,255) };

	vector<Mat> canvas(nc);
	cout<<"inside histogram4"<<endl;
	// Display each histogram in a canvas
	for (int i = 0; i < nc; i++)
	{
		canvas[i] = Mat::ones(125, bins, CV_8UC3);

		for (int j = 0, rows = canvas[i].rows; j < bins-1; j++)
		{
			line(
				canvas[i],
				Point(j, rows),
				Point(j, rows - (hist[i].at<int>(j) * rows/hmax[i])),
				nc == 1 ? Scalar(200,200,200) : colors[i],
				1, 8, 0
			);
		}

		imshow(nc == 1 ? "value" : wname[i], canvas[i]);
	}
}
// Test the `showHistogram()` function above
void histograms(Mat image)
{

	showHistogram(image);
	displayimage("image under histogram function",image);
	waitKey(0);
	return;
}
