#include "util.h"

Utility::Utility()
{
	this->cascadeClassifier.load(this->pathes.haarcascade_frontalface_default_xml);
}
