//
// Created by user on 2021/5/4.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include <QTimer>
#include "process.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->actionOpen_file, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::play);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::stop);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::reset);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openFile() {
    file_name = QFileDialog::getOpenFileName(this, "your video", "", "Video (*.avi)");
    if (file_name == "")return;
    video_capture = cv::VideoCapture(file_name.toStdString());
    fps = video_capture.get(cv::CAP_PROP_FPS);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::timerTick);
    video_capture.read(frame_color);
    first_frame_color = frame_color.clone();
    last_frame_color = frame_color.clone();
}

void MainWindow::timerTick() {
    video_capture.read(frame_color);
    if (frame_color.empty()) {
        video_capture.set(cv::CAP_PROP_POS_FRAMES, 0);
        video_capture.read(frame_color);
    }
    cv::Mat frame_hsi;
    cv::Mat frame_threshold;
    cv::Mat frame_subtracted_f;
    cv::Mat frame_subtracted_l;
    cv::Mat frame_subtracted;
    cv::Mat res;
    cv::subtract(frame_color, first_frame_color, frame_subtracted_f);
    cv::subtract(frame_color, last_frame_color, frame_subtracted_l);
    cv::subtract(frame_subtracted_f, frame_subtracted_l, frame_subtracted);
    frame_hsi = ImageProcess::frame_rgb_to_hsi(frame_subtracted);
    frame_threshold = ImageProcess::fire_detection(frame_subtracted, frame_hsi);
    cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(9, 9), cv::Point(6, 6));
    cv::dilate(frame_threshold, frame_threshold, element);
    cv::bitwise_and(frame_color, frame_color, res, frame_threshold);
    QImage image = QImage(res.data, res.cols, res.rows, QImage::Format_BGR888);
    QImage image_2 = QImage(frame_color.data, frame_color.cols, frame_color.rows, QImage::Format_BGR888);
    image.scaled(ui->label->size(), Qt::KeepAspectRatio);
    image_2.scaled(ui->label_2->size(), Qt::KeepAspectRatio);
    ui->label->setScaledContents(true);
    ui->label_2->setScaledContents(true);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label_2->setPixmap(QPixmap::fromImage(image_2));
    last_frame_color = frame_color.clone();
}

void MainWindow::play() {
    if (frame_color.empty())
        return;
    timer->start(10);
}

void MainWindow::stop() {
    if (frame_color.empty())
        return;
    timer->stop();
}

void MainWindow::reset() {
    if (frame_color.empty())
        return;
    video_capture.set(cv::CAP_PROP_POS_FRAMES, 0);
    video_capture.read(frame_color);
    QImage image = QImage(frame_color.data, frame_color.cols, frame_color.rows, QImage::Format_BGR888);
    QImage image_2 = QImage(frame_color.data, frame_color.cols, frame_color.rows, QImage::Format_BGR888);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label_2->setPixmap(QPixmap::fromImage(image));
    timer->stop();
}




