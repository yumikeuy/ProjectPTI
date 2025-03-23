#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat image = imread("C:/Users/Admin/misha/PW/PTI proj/resources/DSCF3098.JPG", IMREAD_GRAYSCALE);
    if (image.empty()) {
        cerr << "Bad input!" << endl;
        return -1;
    }

    namedWindow("Original image", WINDOW_NORMAL);
    resizeWindow("Original image", 600, 450);
    imshow("Original image", image);


    Mat equalizedImage;
    equalizeHist(image, equalizedImage);

    namedWindow("equalized image", WINDOW_NORMAL);
    resizeWindow("equalized image", 600, 450);
    imshow("equalized image", equalizedImage);

    for(int i = 0; i <= 1; i++)
    {
    int histSize = 256; 
    float range[] = { 0, 256 }; 
    const float* histRange = { range };

    string histname;

    Mat hist;
    Mat img;
    if(i == 0){
        img = image;
        histname = "Histogram 1";
    }
    else{
        img = equalizedImage;
        histname = "Histogram 2";
    }
    
    calcHist(&img, 1, 0, Mat(), hist, 1, &histSize, &histRange);

    
    int hist_w = 512; 
    int hist_h = 400; 
    int bin_w = cvRound((double) hist_w / histSize);

    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255)); 

    normalize(hist, hist, 0, histImage.rows, NORM_MINMAX);

    for (int i = 0; i < histSize; i++) {
        line(histImage,
             Point(bin_w * i, hist_h),
             Point(bin_w * i, hist_h - cvRound(hist.at<float>(i))),
             Scalar(255, 0, 0), 
             1, 8, 0);
    }

    
    imshow(histname, histImage);
}

    
    waitKey(0);
    return 0;
}
