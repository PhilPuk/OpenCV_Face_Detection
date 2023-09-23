#include "camera.h"
#include <opencv2/highgui.hpp>

Camera::Camera()
{
	this->mWidth = 640;
	this->mHeight = 480;
	this->mWindowTitle = "Camera";

	if (this->mCaptureDevice.open(0))
		std::cout << "Camera started succesfully!\n";
	else
		std::cout << "Camera could not start!\n";
}

Camera::~Camera()
{
	this->mCaptureDevice.release();
}

int Camera::getWidth()
{
	return this->mWidth;
}

int Camera::getHeight()
{
	return this->mHeight;
}

std::string Camera::getWindowTitle()
{
	return this->mWindowTitle;
}

cv::VideoCapture& Camera::getCaptureDevice()
{
	return this->mCaptureDevice;
}

void Camera::setWidth(int mWidth)
{
	this->mWidth = mWidth;
}

void Camera::setHeight(int mHeight)
{
	this->mHeight = mHeight;
}

void Camera::renderFrame(cv::Mat& frame)
{
	/*
	* 1. Show the frame in a window.
	* @param frame: The frame to be shown.
	*/
	cv::imshow(this->mWindowTitle, frame);
}

void Camera::restart()
{
	/*
	* 1. Release the camera.
	* 2. Open the camera.
	* 3. If the camera is opened succesfully, print that it worked.
	* 4. Else, print that it failed.
	*/
	mCaptureDevice.release();

	if (this->mCaptureDevice.open(0))
		std::cout << "Camera started succesfully!\n";
	else
		std::cout << "Camera could not start!\n";
}

void Camera::run()
{
	/*
	* 1. Get the current frame from the camera.
	* 2. Render the current frame.
	* 3. Press q to exit from the window.
	* 4. Stop the camera.
	*/
	std::chrono::time_point<std::chrono::high_resolution_clock> prev_frame_time(std::chrono::high_resolution_clock::now());
	std::chrono::time_point<std::chrono::high_resolution_clock> new_frame_time;

	cv::Mat frame, image;
	while(1)
	{
		this->mCaptureDevice >> frame;
		if (frame.empty())
			break;
		this->renderFrame(frame);
		char c = (char) cv::waitKey(10);
		// Press q to exit from the window
		if (c == 27 || c == 'q' || c == 'Q')
			break;

		new_frame_time = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration1(new_frame_time - prev_frame_time);
		int fps = int(1 / duration1.count());
		std::cout << "fps : " << fps << std::endl;

		prev_frame_time = new_frame_time;
	}
	this->stop();
}

void Camera::stop()
{
	mCaptureDevice.release();
}
