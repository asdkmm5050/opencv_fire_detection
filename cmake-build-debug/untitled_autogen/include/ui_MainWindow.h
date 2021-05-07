/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_file;
    QAction *actionplay;
    QAction *actionstop;
    QAction *actionreset;
    QAction *actionf;
    QAction *actionu;
    QAction *actionc;
    QAction *actionk;
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuhelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1030, 600);
        actionOpen_file = new QAction(MainWindow);
        actionOpen_file->setObjectName(QString::fromUtf8("actionOpen_file"));
        actionplay = new QAction(MainWindow);
        actionplay->setObjectName(QString::fromUtf8("actionplay"));
        actionstop = new QAction(MainWindow);
        actionstop->setObjectName(QString::fromUtf8("actionstop"));
        actionreset = new QAction(MainWindow);
        actionreset->setObjectName(QString::fromUtf8("actionreset"));
        actionf = new QAction(MainWindow);
        actionf->setObjectName(QString::fromUtf8("actionf"));
        actionu = new QAction(MainWindow);
        actionu->setObjectName(QString::fromUtf8("actionu"));
        actionc = new QAction(MainWindow);
        actionc->setObjectName(QString::fromUtf8("actionc"));
        actionk = new QAction(MainWindow);
        actionk->setObjectName(QString::fromUtf8("actionk"));
        widget = new QWidget(MainWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 491, 501));
        label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(510, 10, 511, 501));
        label_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 520, 61, 41));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 520, 61, 41));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 520, 61, 41));
        MainWindow->setCentralWidget(widget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1030, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuhelp = new QMenu(menuBar);
        menuhelp->setObjectName(QString::fromUtf8("menuhelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuhelp->menuAction());
        menuFile->addAction(actionOpen_file);
        menuhelp->addAction(actionf);
        menuhelp->addAction(actionu);
        menuhelp->addAction(actionc);
        menuhelp->addAction(actionk);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen_file->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen_file->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionplay->setText(QCoreApplication::translate("MainWindow", "play", nullptr));
        actionstop->setText(QCoreApplication::translate("MainWindow", "stop", nullptr));
        actionreset->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
        actionf->setText(QCoreApplication::translate("MainWindow", "f", nullptr));
        actionu->setText(QCoreApplication::translate("MainWindow", "u", nullptr));
        actionc->setText(QCoreApplication::translate("MainWindow", "c", nullptr));
        actionk->setText(QCoreApplication::translate("MainWindow", "k", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuhelp->setTitle(QCoreApplication::translate("MainWindow", "help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
