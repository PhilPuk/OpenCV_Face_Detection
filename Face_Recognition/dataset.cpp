#include "dataset.h"

Dataset::Dataset()
{

}

Dataset::Dataset(const string& csv_path, const string& names_path)
{
	this->read_csv(csv_path, this->mImages, this->mLabels, ';');
	this->read_names(names_path, this->mNames);
}

Dataset::~Dataset()
{
}

void Dataset::read_csv(const string& filename, vector<Mat>& mImages, vector<int>& mLabels, char separator)
{
	/*
	* 1. Open the file.
	* 2. For each line in the file:
	* 2.1. Get the path and the label.
	* 2.2. If the path and the label are not empty:
	* 2.2.1. Read the image.
	* 2.2.2. Add the image to the vector of images.
	* 2.2.3. Add the label to the vector of labels.
	* 3. Close the file.
	* @param filename: path to the csv file
	* @param mImages: vector of images
	* @param mLabels: vector of labels
	* @param separator: separator of the csv file
	*/
	ifstream file(filename.c_str(), ifstream::in);

	if (!file)
		CV_Error(Error::StsBadArg, "No valid input file was given, please check the given filename.");

	string line, path, classlabel;
	while (std::getline(file, line))
	{
		stringstream liness(line);
		std::getline(liness, path, separator);
		std::getline(liness, classlabel);
		if (!path.empty() and !classlabel.empty())
		{
			int label = atoi(classlabel.c_str());
			string complete_path = "../Face_Recognition/my_dataset/pre_processed/" + to_string(label) + "/" + path;
			mImages.push_back(imread(complete_path, 0));
			mLabels.push_back(label);
		}
	}
}

void Dataset::read_names(const string& filename, vector<string>& mNames)
{
	/*
	* 1. Open the file.
	* 2. For each line in the file:
	* 2.1. Get the name.
	* 2.2. If the name is not empty:
	* 2.2.1. Add the name to the vector of names.
	* 3. Close the file.
	* @param filename: path to the txt file
	* @param mNames: vector of names
	*/
	ifstream file(filename.c_str(), ifstream::in);

	if (!file)
		assert("No valid input file was given, please check the given filename.");
	string line;
	while (std::getline(file, line))
		mNames.push_back(line);

}

