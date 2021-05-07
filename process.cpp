//
// Created by user on 2021/5/5.
//

#include "process.h"

ImageProcess::ImageProcess(cv::Mat input) {
    this->input = input;
}

void ImageProcess::BGRtoHSI(int R, int G, int B, int &H, int &S, int &I) {
    auto r = (double) R / (R + G + B);
    auto g = (double) G / (R + G + B);
    auto b = (double) B / (R + G + B);
    I = (R + G + B) / 3;
    S = (1 - 3 * std::min(r, std::min(g, b))) * 255;
    H = std::acos((0.5 * ((r - g) + (r - b))) / (std::sqrt((r - g) * (r - g) + (r - b) * (g - b))));
}

bool ImageProcess::rule1(int R, int r) {
    if (R > r)
        return true;
    else
        return false;
}

bool ImageProcess::rule2(int R, int G, int B) {
    if (R >= G && G > B)
        return true;
    else
        return false;
}

bool ImageProcess::rule3(int R, int S, int r, int s) {
    auto value = (255 - R) * s / r;
    if (S >= value)
        return true;
    else
        return false;
}

bool ImageProcess::rule4(int I, int i) {
    if (I > i)
        return true;
    else
        return false;
}

cv::Mat ImageProcess::frame_rgb_to_hsi(cv::Mat input) {
    cv::Mat output = input.clone();
    auto input_data = input.data;
    auto output_data = output.data;
    int H = 0;
    int S = 0;
    int I = 0;
    input_data = input.data;
    output_data = output.data;
    for (int y = 0; y < input.cols; y++) {
        for (int x = 0; x < input.rows; x++) {
            BGRtoHSI(input_data[0], input_data[1], input_data[2], H, S, I);
            output_data[0] = (uchar) H;
            output_data[1] = (uchar) S;
            output_data[2] = (uchar) I;
            input_data += 3;
            output_data += 3;
        }
    }
    return output.clone();
}

cv::Mat ImageProcess::fire_detection(cv::Mat frame_color, cv::Mat frame_hsi) {
    cv::Mat output = cv::Mat(frame_color.rows, frame_color.cols, CV_8UC1);
    auto frame_color_data = frame_color.data;
    auto frame_hsi_data = frame_hsi.data;
    auto output_data = output.data;
    int R, G, B, H, S, I;
    int r = 125;
    int s = 55;
    int i = 80;
    for (int y = 0; y < frame_color.cols; y++) {
        for (int x = 0; x < frame_color.rows; x++) {
            B = frame_color_data[0];
            G = frame_color_data[1];
            R = frame_color_data[2];
            H = frame_hsi_data[0];
            S = frame_hsi_data[1];
            I = frame_hsi_data[2];
            if (rule1(R, r) && rule2(R, G, B) && rule3(R, S, r, s) && rule4(I, i))
                output_data[0] = 255;
            else
                output_data[0] = 0;
            frame_color_data += 3;
            frame_hsi_data += 3;
            output_data += 1;
        }
    }
    return output.clone();
}


