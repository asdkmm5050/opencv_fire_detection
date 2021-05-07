//
// Created by user on 2021/5/4.
//

#ifndef UNTITLED_MAINWINDOW_H
#define UNTITLED_MAINWINDOW_H

#include <QMainWindow>
#include "opencv2/opencv.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots :
    void openFile();
    void timerTick();
    void play();
    void stop();
    void reset();
private:
    Ui::MainWindow *ui;
    cv::VideoCapture video_capture;
    QTimer* timer = nullptr;
    QString file_name;
    cv::Mat frame_color;
    cv::Mat first_frame_color;
    cv::Mat last_frame_color;
    int fps;
};


#endif //UNTITLED_MAINWINDOW_H
