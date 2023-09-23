#include "model.h"

Model::Model()
{
	this->mModel = cv::face::EigenFaceRecognizer::create();
}

Model::~Model()
{
	delete this->mModel;
}

Ptr<cv::face::EigenFaceRecognizer>& Model::getModel()
{
	return this->mModel;
}

void Model::trainModel(std::vector<cv::Mat>& images, std::vector<int>& labels)
{
	this->mModel->train(images, labels);
}

int Model::predict(cv::Mat& image)
{
	return this->mModel->predict(image);
}
