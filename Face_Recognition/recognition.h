#pragma once
#include"model.h"
#include"camera.h"
#include"detection.h"
#include"util.h"
#include<iostream>

class Recognition
{
private:
	Model mModel;
	Detection mDetection;
	Utility mUtil;
public:
	Recognition();
	virtual ~Recognition();

	void run();
};

