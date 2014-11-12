/*
 *      Author: alexanderb
 */

#include <opencv2/opencv.hpp>

#include "Util.h"

using namespace std;
using namespace cv;

class Harris {
public:
    Harris(Mat img, float k, int filterRange);
	vector<pointData> getMaximaPoints(float percentage, int filterRange, int suppressionRadius);

private:
	Mat convertRgbToGrayscale(Mat& img);
	Derivatives computeDerivatives(Mat& greyscaleImg);	
	Derivatives applyMeanToDerivatives(Derivatives& dMats, int filterRange);
	Mat computeHarrisResponses(float k, Derivatives& intMats);

	Mat computeIntegralImg(Mat& img);
	Mat meanFilter(Mat& intImg, int range);

private:
	Mat m_harrisResponses;
};