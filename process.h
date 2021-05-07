//
// Created by user on 2021/5/5.
//

#ifndef UNTITLED_PROCESS_H
#define UNTITLED_PROCESS_H

#include "opencv2/opencv.hpp"

class ImageProcess {
public:
    explicit ImageProcess(cv::Mat);

    static void BGRtoHSI(int, int, int, int &, int &, int &);

    static cv::Mat frame_rgb_to_hsi(cv::Mat);

    static cv::Mat fire_detection(cv::Mat, cv::Mat);

    static bool rule1(int, int);

    static bool rule2(int, int, int);

    static bool rule3(int, int, int, int);

    static bool rule4(int, int);

private:
    cv::Mat input;
    cv::Mat output;
};

#endif //UNTITLED_PROCESS_H
