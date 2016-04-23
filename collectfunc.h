/*
 * collectfunc.h
 *
 *  Created on: 25-Aug-2015
 *      Author: deepak
 */
#ifndef COLLECTFUNC_H_
#define COLLECTFUNC_H_

#include <opencv2/opencv.hpp>

void displayimage(char*,cv::Mat );
cv::Mat convertingrayimage(char **);
void findminfilter(cv::Mat );
void findmaxfilter(cv::Mat );
cv::Mat conv2(cv::Mat , int);
void medianfilter(cv::Mat );
void histogramequalization(cv::Mat );
void transformations(cv::Mat);
void histograms(cv::Mat);
#endif /* COLLECTFUNC_H_ */

