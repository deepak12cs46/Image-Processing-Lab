#include<cv.h>
#include<iostream>
#include<stdio.h>
#include<highgui.h>
#include "collectfunc.h"
using namespace cv ;
using namespace std;
Mat convertingrayimage(char ** argv)
{
	char *imagename = argv[1];
	Mat image ;
	image = imread(imagename , 1);
	Mat grayImage ;
	cvtColor(image , grayImage , CV_BGR2GRAY);
	//imwrite("abcd.jpg" , grayImage);
	namedWindow(" Display Grayscale" , CV_WINDOW_AUTOSIZE);
	imshow(" Display Grayscale" , grayImage);

	int m = grayImage.rows;
		int n = grayImage.cols;
		cout<<m<<endl;
		cout<<n<<endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int pixel = (int)grayImage.at<uchar>(i, j);
				//con1+=(pixel*pixel);
				//con2 += pixel;
				printf("%d " , pixel);
			}
			printf("\n");
		}
	waitKey(0);
	return grayImage;
}
