#pragma once
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/face.hpp"
#include "dataset.h"
#include<vector>
#include<iostream>

class Model
{
private:
	Ptr<cv::face::EigenFaceRecognizer> mModel;
public:
	Model();
	virtual ~Model();
	

	Ptr<cv::face::EigenFaceRecognizer>& getModel();

	void trainModel(std::vector<cv::Mat>& images, std::vector<int>& labels);

	int predict(cv::Mat& image);
};

