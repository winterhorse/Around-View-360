#pragma once

#include "stdafx.h"


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/stitching.hpp>
#include <iostream>
#include <vector>  


#define camMaxNum 6

class CamCapture							//采集多路视频
{

private:
	//VideoCapture videoCapture(0);
public:
	//CamCapture& videoSave();
	CamCapture & capture(int camSeq, int width, int heigth, double fps, string savePath);		//单摄像头采集视频 savePath为保存的路径
	bool capture(int camNum, int width, int heigth, int cols, int rows, double fps, char saveDirName[], bool isReleaseCam);	//多摄像头同时采集视频 saveDirPath为保存的文件夹路径
	void showImgsOneWindow(vector<Mat>& Images, Mat& dst, int width, int height, int cols, int rows);
	void printStringOnImgCenter(Mat & img, const String & text, int fontFace, double fontScale, Scalar color, int thickness = 1, int lineType = LINE_8, bool bottomLeftOrigin = false);
};

void stitch(vector<Mat> imgs, Mat& resultMat);						//OpenCV自带的Stitch方法
void stitch2(Mat& srcImage1, Mat& srcImage2, Mat& panorama);		//另一种相似的拼接方法
