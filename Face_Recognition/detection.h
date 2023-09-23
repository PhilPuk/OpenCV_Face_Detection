#pragma once

#include "opencv2\objdetect.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include "camera.h"
#include <iostream>

using namespace std;
using namespace cv;

class detection
{
private:
	Scalar mFrameColor;
public:
	detection();
	detection(Scalar frameColor);

	~detection();

	cv::Mat& detectOnImages(cv::Mat& image, cv::CascadeClassifier& cascadeClassifier, double scale);

	void run(cv::CascadeClassifier& cascadeClassifier);
};

