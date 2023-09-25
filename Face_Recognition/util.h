#pragma once
#include "opencv2\objdetect.hpp"
#include<iostream>
#include<string>
#include<vector>

struct Pathes
{
	const std::string haarcascade_frontalface_default_xml = "haarcascade_frontalface_default.xml";
	//Old pathes
	const std::string names_txt = "../names.txt";
	const std::string pre_processed_csv = "../pre_processed_csv.csv";
	const std::string haarcascade_frontalface_alt_xml = "../Face_Recognition/haarcascades/haarcascade_frontalface_alt.xml";
	const std::string haarcascade_eye_tree_eyeglasses_xml = "../haarcascade_eye_tree_eyeglasses.xml";
};

class Utility
{
public:
	Utility();

	cv::CascadeClassifier cascadeClassifier;
	Pathes pathes;

	template<typename T>
	void printVector(const std::vector<T>& list)
	{
		/*
		* Print the elements of a vector
		* @param list: vector to print
		*/
		if (!list.empty())
			for (const auto& element : list)
				std::cout << element << std::endl;
		else
		{
			printWarning(__FILE__, "Vector is empty");
		}
	}

	void printWarning(std::string file_function, std::string msg)
	{
		/*
		* Print a warning message
		* @param file_function: file and function name as string where the warning is generated
		* @param msg: warning message
		*/
		std::cout << "\033[93m" << "WARNING IN:: " << file_function << ":: " << msg << std::endl << "\033[0m";
	}
};

