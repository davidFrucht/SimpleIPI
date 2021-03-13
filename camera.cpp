#include "header.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
using namespace Calc;

camera::camera()
{

}

System::Drawing::Bitmap^ camera::Show(cv::Mat& colorimage)
{
	System::IntPtr ptr(colorimage.ptr());
	System::Drawing::Bitmap^ b;
	switch (colorimage.type())
	{
	case CV_8UC3:
		b = gcnew System::Drawing::Bitmap(colorimage.cols, colorimage.rows, colorimage.step,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
		break;
	case CV_8UC1:
		b = gcnew System::Drawing::Bitmap(colorimage.cols, colorimage.rows, colorimage.step,
			System::Drawing::Imaging::PixelFormat::Format8bppIndexed, ptr);
		break;
	default:
		break;

	}
	return b;
}

