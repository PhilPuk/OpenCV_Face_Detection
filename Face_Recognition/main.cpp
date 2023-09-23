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
	Utility util;
	Dataset dataset(util.pathes.pre_processed_csv, util.pathes.names_txt);
	cv::CascadeClassifier cascadeClassifier, nestedCascade;
	cascadeClassifier.load(util.pathes.haarcascade_frontalface_default_xml);
	nestedCascade.load(util.pathes.haarcascade_eye_tree_eyeglasses_xml);

	detection detect;
	detect.run(util.cascadeClassifier);
	Camera camera;
	//camera.run();
}