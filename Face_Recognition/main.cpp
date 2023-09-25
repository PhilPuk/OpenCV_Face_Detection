#include "opencv2\objdetect.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include <iostream>

#include"camera.h"
#include"dataset.h"
#include"detection.h"
#include"util.h"


int main(int argc, const char** argv)
{
	cv::CascadeClassifier cascadeClassifier;
	cascadeClassifier.load(Utility().pathes.haarcascade_frontalface_default_xml);
	Detection().run(cascadeClassifier);
}