// main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "VideoStitch.h"

int main()
{
	const bool isRebuild = false;
	const bool isReleaseCam = false;
	CamCapture camCapture;
	VideoStitch videoStitch;
	StitchFrame stitchFrame;
	const unsigned int camCols = 1;
	const unsigned int camRows = 1;
	const unsigned int camNum = camCols * camRows;
	char dirName[80];
	
	//获取当期系统时间
	time_t tt = time(NULL);
	tm* t = localtime(&tt);

	//初始化文件夹名称
	sprintf(dirName, "Video_%d_%02d_%02d_%02d%02d%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

	//创建用于保存视频的目录
	if (_mkdir(dirName) == 0)
		printf("\nSuccessfully created the folder : .\\%s \n", dirName);
	else
	{
		printf("\nCan not create folder,the folder may already created.\n");
		waitKey(0);
		exit(1);
	}

	if (camCapture.capture(camNum, 1280, 720, camCols, camRows, 24.0, dirName, isReleaseCam) == false)
	{
		waitKey(0);
		exit(1);
	}
	//sprintf(dirName, "%s", "Video_2018_03_22_214708_OK_OK");
	if (videoStitch.readVideo(dirName) == false)
	{
		waitKey(0);
		exit(1);
	}

	sprintf(dirName, "Video_%d_%02d_%02d_%02d%02d%02d\\outPut.avi", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
	//sprintf(dirName, "%s", "Video_2018_03_22_214708_OK_OK\\outPut.avi");

	videoStitch.stitchVideo(dirName, isRebuild);
	
	




	/*sprintf(dirName, "Video_%d_%02d_%02d_%02d%02d%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
	videoStitch.readVideo(dirName);
	sprintf(dirName, "Video_%d_%02d_%02d_%02d%02d%02d\\outPut2.avi", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
	videoStitch.stitchVideo2(dirName);
*/


	/*stitchFrame.setSRC_L("IMG_20180318_002729.jpg");
	stitchFrame.setSRC_R("IMG_20180318_002710.jpg");
	stitchFrame.findH("H.xml",STITCH_SIFT,true);
	stitchFrame.show("test");
	namedWindow("result", WINDOW_KEEPRATIO);
	imshow("result",stitchFrame.stitch(20));
	waitKey(0);*/
    return 0;
}

