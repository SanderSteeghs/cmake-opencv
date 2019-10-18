#include "blindshot-config.hpp"
#include "blindshot/Example.hpp"

#include "blindshot/Cam/ICamera.hpp"

#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    // This is an example. See CMakeList.txt how to add source code files and header files
    Example example;

    ICamera *cam = new PlatformCam();
    cam->init();

    while(true) {
        cv::Mat frame;
        cam->capture(frame);

        cv::flip(frame, frame, 1);
        cv::imshow("monkey", frame);
        cv::waitKey(1);
    }

    std::cout << "it was nice to have existed" << std::endl;
    return 0;
}
