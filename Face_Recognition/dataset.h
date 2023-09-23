#pragma once
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace cv;
using namespace std;


class Dataset
{
private:
	vector<Mat> mImages;
	vector<int> mLabels;
	vector<string> mNames;
public:
	Dataset();
	Dataset(const string& csv_path, const string& names_path);
	virtual ~Dataset();

	vector<string>& getNamesWithID() { return this->mNames; }
	vector<Mat>& getImages() { return this->mImages; }	
	vector<int>& getLabels() { return this->mLabels; }	

	static void read_csv(const string& filename, vector<Mat>& mImages, vector<int>& mLabels, char separator = ';');
	static void read_names(const string& filename, vector<string>& mNames);

};

