#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv )
{
    char cam_number = 0;
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out CAMERA_NUMBER\nUsing default Camera 0!\n");
    }
    else
    {
	     cam_number = (char)*argv[1] - 48;
       printf("using camera %i\n", cam_number);
	  }

  // Setup camera and window
  VideoCapture stream1(cam_number);
  Mat image;
  namedWindow("Display Image", WINDOW_AUTOSIZE );
  std::vector<KeyPoint> keypoints;

  // loop infinitely
  while(true)
  {
      stream1.read(image);
      if ( !image.data )
      {
          printf("No image data \n");
          return -1;
      }

      // convert to grayscale
      cvtColor(image, image, CV_BGR2GRAY);

      // find keypoints
      FAST(image, keypoints, 20, true);
      drawKeypoints(image, keypoints, image, Scalar::all(255));

      // display image
      imshow("Display Image", image);
      waitKey(30);
  }
    return 0;
}
