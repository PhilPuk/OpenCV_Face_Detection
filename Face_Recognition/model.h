#pragma once
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/face.hpp"
#include "dataset.h"
#include<vector>
#include<iostream>

class model
{
private:
	//Create a smart pointer that is for the eigenFaceRecognizer
	Ptr<EigenFaceRecognizer> mModel;
public:
	model();
	virtual ~model();
	

};

