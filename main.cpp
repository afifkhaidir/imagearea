#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    int area = 0, perimeter_value = 0;

    // Load original image
    IplImage *src = cvLoadImage("avocado.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    cvShowImage("Grayscale", src);

    // Create destination image
    IplImage *dst = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
    cvThreshold(src,dst,250,255,CV_THRESH_BINARY_INV);

    // Image enhancement for noise removal (optional)
    cvSmooth(dst,dst,CV_MEDIAN,3);

    // Create matrices of dst image
    Mat img1(dst);
    cvShowImage("Result", dst);

    // Calculate area of image
    for(int i=0; i < dst->height; i++){
        for(int j=0; j < dst->width; j++ ){
            Scalar intensity = img1.at<uchar>(Point(i, j));
            if(intensity[0]==255) area++;
        }
    }

    // Implement dilation to calculate perimeter of image
    IplImage *dilateImg = cvCloneImage(dst);
    cvDilate(dilateImg,dilateImg,NULL,1);
    Mat dilated(dilateImg);
    bitwise_not(dilated,dilated);
    cvShowImage("Dilated Invers", dilateImg);

    // Adding dilated invers image with binary image
    IplImage *perimeter = cvCreateImage(cvGetSize(dst),IPL_DEPTH_8U,1);
    cvAdd(dst,dilateImg,perimeter);
    Mat perimeter_img(perimeter);
    cvShowImage("Perimeter", perimeter);

    // Calculate perimeter of the image
    for(int i=0; i < perimeter->height; i++){
        for(int j=0; j < perimeter->width; j++){
            Scalar intensity = perimeter_img.at<uchar>(Point(i,j));
            if(intensity[0]==0) perimeter_value++;
        }
    }

    cout << "Area of the image is " << area << " pixel" << endl;
    cout << "Perimeter of the image is " << perimeter_value << " pixel" << endl;

    cvWaitKey(0);
    return 0;
}
