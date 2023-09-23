#pragma once
#include<iostream>
#include "opencv2\videoio.hpp"

class Camera
{
private:
	int mWidth;
	int mHeight;
	std::string mWindowTitle; 
	cv::VideoCapture mCaptureDevice;
public:
	Camera();
	~Camera();

	int getWidth();
	int getHeight();
	std::string getWindowTitle();
	cv::VideoCapture& getCaptureDevice();

	void setWidth(int mWidth);
	void setHeight(int mHeight);

	void renderFrame(cv::Mat& frame);

	void restart();
	void run();
	void stop();
};

