// Martin Kersner, m.kersner@gmail.com
// 2016/12/18

#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include "utils.hpp"
#include "nms.hpp"

int threshold_max = 100;
std::vector<std::vector<float> > rectangles =
{
  {300, 300, 400, 400},
  {320, 320, 420, 420},
  {295, 259, 415, 415},
  {100, 100, 150, 150},
  {90,  90,  180, 180},
  {112, 112, 170, 170}
};

static void on_trackbar(int threshold_percent, void *)
{
  cv::Mat imgAfter(cv::Size(500, 500), cv::DataType<float>::type);
  float threshold = (float) threshold_percent / threshold_max;
  std::vector<cv::Rect> reducedRectangle = nms(rectangles, threshold);
  DrawRectangles(imgAfter, reducedRectangle);
  cv::imshow("After", imgAfter);
}

int main()
{
  // initialization
  cv::Mat imgBefore(cv::Size(500, 500), cv::DataType<float>::type);
  int threshold_percent = 10;

  // before
  DrawRectangles(imgBefore, rectangles);
  cv::imshow("Before", imgBefore);

  cv::namedWindow("After", cv::WINDOW_AUTOSIZE);
  char TrackbarName[50];
  sprintf( TrackbarName, "Threshold (%%)");
  cv::createTrackbar( TrackbarName, "After", &threshold_percent, threshold_max, on_trackbar );
  
  // after
  
  cv::waitKey(0);
}
