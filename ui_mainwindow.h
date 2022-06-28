/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QChartView *graphicsView;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_3;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_D_H;
    QLineEdit *lineEdit_P_H;
    QLineEdit *lineEdit_I_H;
    QLineEdit *lineEdit_P_H_2;
    QLineEdit *lineEdit_I_H_2;
    QLineEdit *lineEdit_D_H_2;
    QPushButton *pushButton_setPID_H;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *lineEdit_speed_H;
    QPushButton *move_H;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label;
    QLineEdit *sine_mag_H;
    QLabel *label_2;
    QLineEdit *sine_freq_H;
    QPushButton *sine_H;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *lineEdit_setspeed_H;
    QPushButton *setSpeed_H;
    QFrame *frame_4;
    QGridLayout *gridLayout_4;
    QLineEdit *target_H;
    QLineEdit *actual_H;
    QLabel *label_9;
    QLineEdit *error_H;
    QLabel *label_10;
    QLineEdit *speed_H;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_12;
    QLineEdit *RMS_H;
    QVBoxLayout *verticalLayout_4;
    QPushButton *stop_showH;
    QPushButton *enable_H;
    QPushButton *stop_H;
    QVBoxLayout *verticalLayout_2;
    QChartView *graphicsView_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEdit_speed_AZ;
    QPushButton *move_AZ;
    QGridLayout *gridLayout_6;
    QLineEdit *lineEdit_D_AZ;
    QLineEdit *lineEdit_P_AZ;
    QLineEdit *lineEdit_I_AZ;
    QLineEdit *lineEdit_P_AZ_2;
    QLineEdit *lineEdit_I_AZ_2;
    QLineEdit *lineEdit_D_AZ_2;
    QPushButton *pushButton_setPID_AZ;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_3;
    QLineEdit *sine_mag_AZ;
    QLabel *label_14;
    QLineEdit *sine_freq_AZ;
    QPushButton *sine_AZ;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *lineEdit_setspeed_AZ;
    QPushButton *setSpeed_AZ;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QLineEdit *target_AZ;
    QLineEdit *speed_AZ;
    QLabel *label_6;
    QLabel *label_11;
    QLineEdit *actual_AZ;
    QLineEdit *error_AZ;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_13;
    QLineEdit *RMS_AZ;
    QVBoxLayout *verticalLayout_5;
    QPushButton *stop_showAZ;
    QPushButton *enable_AZ;
    QPushButton *stop_AZ;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1800, 800);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QChartView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        frame_3 = new QFrame(groupBox_4);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(9, 0, 9, 0);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        lineEdit_D_H = new QLineEdit(frame_3);
        lineEdit_D_H->setObjectName(QString::fromUtf8("lineEdit_D_H"));

        gridLayout_5->addWidget(lineEdit_D_H, 0, 2, 1, 1);

        lineEdit_P_H = new QLineEdit(frame_3);
        lineEdit_P_H->setObjectName(QString::fromUtf8("lineEdit_P_H"));

        gridLayout_5->addWidget(lineEdit_P_H, 0, 0, 1, 1);

        lineEdit_I_H = new QLineEdit(frame_3);
        lineEdit_I_H->setObjectName(QString::fromUtf8("lineEdit_I_H"));

        gridLayout_5->addWidget(lineEdit_I_H, 0, 1, 1, 1);

        lineEdit_P_H_2 = new QLineEdit(frame_3);
        lineEdit_P_H_2->setObjectName(QString::fromUtf8("lineEdit_P_H_2"));

        gridLayout_5->addWidget(lineEdit_P_H_2, 1, 0, 1, 1);

        lineEdit_I_H_2 = new QLineEdit(frame_3);
        lineEdit_I_H_2->setObjectName(QString::fromUtf8("lineEdit_I_H_2"));

        gridLayout_5->addWidget(lineEdit_I_H_2, 1, 1, 1, 1);

        lineEdit_D_H_2 = new QLineEdit(frame_3);
        lineEdit_D_H_2->setObjectName(QString::fromUtf8("lineEdit_D_H_2"));

        gridLayout_5->addWidget(lineEdit_D_H_2, 1, 2, 1, 1);

        pushButton_setPID_H = new QPushButton(frame_3);
        pushButton_setPID_H->setObjectName(QString::fromUtf8("pushButton_setPID_H"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_setPID_H->sizePolicy().hasHeightForWidth());
        pushButton_setPID_H->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(pushButton_setPID_H, 0, 3, 2, 1);


        gridLayout_3->addLayout(gridLayout_5, 1, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        lineEdit_speed_H = new QLineEdit(frame_3);
        lineEdit_speed_H->setObjectName(QString::fromUtf8("lineEdit_speed_H"));

        horizontalLayout_11->addWidget(lineEdit_speed_H);

        move_H = new QPushButton(frame_3);
        move_H->setObjectName(QString::fromUtf8("move_H"));

        horizontalLayout_11->addWidget(move_H);


        gridLayout_3->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_16->addWidget(label);

        sine_mag_H = new QLineEdit(frame_3);
        sine_mag_H->setObjectName(QString::fromUtf8("sine_mag_H"));

        horizontalLayout_16->addWidget(sine_mag_H);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_16->addWidget(label_2);

        sine_freq_H = new QLineEdit(frame_3);
        sine_freq_H->setObjectName(QString::fromUtf8("sine_freq_H"));

        horizontalLayout_16->addWidget(sine_freq_H);

        sine_H = new QPushButton(frame_3);
        sine_H->setObjectName(QString::fromUtf8("sine_H"));

        horizontalLayout_16->addWidget(sine_H);


        gridLayout_3->addLayout(horizontalLayout_16, 3, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        lineEdit_setspeed_H = new QLineEdit(frame_3);
        lineEdit_setspeed_H->setObjectName(QString::fromUtf8("lineEdit_setspeed_H"));

        horizontalLayout_13->addWidget(lineEdit_setspeed_H);

        setSpeed_H = new QPushButton(frame_3);
        setSpeed_H->setObjectName(QString::fromUtf8("setSpeed_H"));

        horizontalLayout_13->addWidget(setSpeed_H);


        gridLayout_3->addLayout(horizontalLayout_13, 2, 0, 1, 1);


        horizontalLayout_5->addWidget(frame_3);

        frame_4 = new QFrame(groupBox_4);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(30, 0, 30, 0);
        target_H = new QLineEdit(frame_4);
        target_H->setObjectName(QString::fromUtf8("target_H"));

        gridLayout_4->addWidget(target_H, 2, 1, 1, 1);

        actual_H = new QLineEdit(frame_4);
        actual_H->setObjectName(QString::fromUtf8("actual_H"));

        gridLayout_4->addWidget(actual_H, 1, 1, 1, 1);

        label_9 = new QLabel(frame_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 2, 0, 1, 1);

        error_H = new QLineEdit(frame_4);
        error_H->setObjectName(QString::fromUtf8("error_H"));

        gridLayout_4->addWidget(error_H, 3, 1, 1, 1);

        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 3, 0, 1, 1);

        speed_H = new QLineEdit(frame_4);
        speed_H->setObjectName(QString::fromUtf8("speed_H"));

        gridLayout_4->addWidget(speed_H, 0, 1, 1, 1);

        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 1, 0, 1, 1);

        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        label_12 = new QLabel(frame_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 4, 0, 1, 1);

        RMS_H = new QLineEdit(frame_4);
        RMS_H->setObjectName(QString::fromUtf8("RMS_H"));

        gridLayout_4->addWidget(RMS_H, 4, 1, 1, 1);


        horizontalLayout_5->addWidget(frame_4);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        stop_showH = new QPushButton(groupBox_4);
        stop_showH->setObjectName(QString::fromUtf8("stop_showH"));

        verticalLayout_4->addWidget(stop_showH);

        enable_H = new QPushButton(groupBox_4);
        enable_H->setObjectName(QString::fromUtf8("enable_H"));

        verticalLayout_4->addWidget(enable_H);

        stop_H = new QPushButton(groupBox_4);
        stop_H->setObjectName(QString::fromUtf8("stop_H"));
        sizePolicy.setHeightForWidth(stop_H->sizePolicy().hasHeightForWidth());
        stop_H->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(stop_H);


        horizontalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(2, 1);

        verticalLayout->addWidget(groupBox_4);

        verticalLayout->setStretch(0, 6);
        verticalLayout->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        graphicsView_2 = new QChartView(centralWidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));

        verticalLayout_2->addWidget(graphicsView_2);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        frame = new QFrame(groupBox_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 0, 9, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        lineEdit_speed_AZ = new QLineEdit(frame);
        lineEdit_speed_AZ->setObjectName(QString::fromUtf8("lineEdit_speed_AZ"));

        horizontalLayout_10->addWidget(lineEdit_speed_AZ);

        move_AZ = new QPushButton(frame);
        move_AZ->setObjectName(QString::fromUtf8("move_AZ"));

        horizontalLayout_10->addWidget(move_AZ);


        gridLayout->addLayout(horizontalLayout_10, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        lineEdit_D_AZ = new QLineEdit(frame);
        lineEdit_D_AZ->setObjectName(QString::fromUtf8("lineEdit_D_AZ"));

        gridLayout_6->addWidget(lineEdit_D_AZ, 0, 2, 1, 1);

        lineEdit_P_AZ = new QLineEdit(frame);
        lineEdit_P_AZ->setObjectName(QString::fromUtf8("lineEdit_P_AZ"));

        gridLayout_6->addWidget(lineEdit_P_AZ, 0, 0, 1, 1);

        lineEdit_I_AZ = new QLineEdit(frame);
        lineEdit_I_AZ->setObjectName(QString::fromUtf8("lineEdit_I_AZ"));

        gridLayout_6->addWidget(lineEdit_I_AZ, 0, 1, 1, 1);

        lineEdit_P_AZ_2 = new QLineEdit(frame);
        lineEdit_P_AZ_2->setObjectName(QString::fromUtf8("lineEdit_P_AZ_2"));

        gridLayout_6->addWidget(lineEdit_P_AZ_2, 1, 0, 1, 1);

        lineEdit_I_AZ_2 = new QLineEdit(frame);
        lineEdit_I_AZ_2->setObjectName(QString::fromUtf8("lineEdit_I_AZ_2"));

        gridLayout_6->addWidget(lineEdit_I_AZ_2, 1, 1, 1, 1);

        lineEdit_D_AZ_2 = new QLineEdit(frame);
        lineEdit_D_AZ_2->setObjectName(QString::fromUtf8("lineEdit_D_AZ_2"));

        gridLayout_6->addWidget(lineEdit_D_AZ_2, 1, 2, 1, 1);

        pushButton_setPID_AZ = new QPushButton(frame);
        pushButton_setPID_AZ->setObjectName(QString::fromUtf8("pushButton_setPID_AZ"));
        sizePolicy.setHeightForWidth(pushButton_setPID_AZ->sizePolicy().hasHeightForWidth());
        pushButton_setPID_AZ->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(pushButton_setPID_AZ, 0, 3, 2, 1);


        gridLayout->addLayout(gridLayout_6, 1, 0, 1, 1);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_17->addWidget(label_3);

        sine_mag_AZ = new QLineEdit(frame);
        sine_mag_AZ->setObjectName(QString::fromUtf8("sine_mag_AZ"));

        horizontalLayout_17->addWidget(sine_mag_AZ);

        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_17->addWidget(label_14);

        sine_freq_AZ = new QLineEdit(frame);
        sine_freq_AZ->setObjectName(QString::fromUtf8("sine_freq_AZ"));

        horizontalLayout_17->addWidget(sine_freq_AZ);

        sine_AZ = new QPushButton(frame);
        sine_AZ->setObjectName(QString::fromUtf8("sine_AZ"));

        horizontalLayout_17->addWidget(sine_AZ);


        gridLayout->addLayout(horizontalLayout_17, 3, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lineEdit_setspeed_AZ = new QLineEdit(frame);
        lineEdit_setspeed_AZ->setObjectName(QString::fromUtf8("lineEdit_setspeed_AZ"));

        horizontalLayout_9->addWidget(lineEdit_setspeed_AZ);

        setSpeed_AZ = new QPushButton(frame);
        setSpeed_AZ->setObjectName(QString::fromUtf8("setSpeed_AZ"));

        horizontalLayout_9->addWidget(setSpeed_AZ);


        gridLayout->addLayout(horizontalLayout_9, 2, 0, 1, 1);


        horizontalLayout_4->addWidget(frame);

        frame_2 = new QFrame(groupBox_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(30, 0, 30, 0);
        target_AZ = new QLineEdit(frame_2);
        target_AZ->setObjectName(QString::fromUtf8("target_AZ"));

        gridLayout_2->addWidget(target_AZ, 2, 1, 1, 1);

        speed_AZ = new QLineEdit(frame_2);
        speed_AZ->setObjectName(QString::fromUtf8("speed_AZ"));

        gridLayout_2->addWidget(speed_AZ, 0, 1, 1, 1);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 3, 0, 1, 1);

        actual_AZ = new QLineEdit(frame_2);
        actual_AZ->setObjectName(QString::fromUtf8("actual_AZ"));

        gridLayout_2->addWidget(actual_AZ, 1, 1, 1, 1);

        error_AZ = new QLineEdit(frame_2);
        error_AZ->setObjectName(QString::fromUtf8("error_AZ"));

        gridLayout_2->addWidget(error_AZ, 3, 1, 1, 1);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_13 = new QLabel(frame_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 4, 0, 1, 1);

        RMS_AZ = new QLineEdit(frame_2);
        RMS_AZ->setObjectName(QString::fromUtf8("RMS_AZ"));

        gridLayout_2->addWidget(RMS_AZ, 4, 1, 1, 1);


        horizontalLayout_4->addWidget(frame_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        stop_showAZ = new QPushButton(groupBox_2);
        stop_showAZ->setObjectName(QString::fromUtf8("stop_showAZ"));

        verticalLayout_5->addWidget(stop_showAZ);

        enable_AZ = new QPushButton(groupBox_2);
        enable_AZ->setObjectName(QString::fromUtf8("enable_AZ"));

        verticalLayout_5->addWidget(enable_AZ);

        stop_AZ = new QPushButton(groupBox_2);
        stop_AZ->setObjectName(QString::fromUtf8("stop_AZ"));
        sizePolicy.setHeightForWidth(stop_AZ->sizePolicy().hasHeightForWidth());
        stop_AZ->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(stop_AZ);


        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(2, 1);

        verticalLayout_2->addWidget(groupBox_2);

        verticalLayout_2->setStretch(0, 6);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        horizontalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1800, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\351\253\230\345\272\246\350\275\264", nullptr));
        lineEdit_D_H->setPlaceholderText(QCoreApplication::translate("MainWindow", "D", nullptr));
        lineEdit_P_H->setInputMask(QString());
        lineEdit_P_H->setText(QString());
        lineEdit_P_H->setPlaceholderText(QCoreApplication::translate("MainWindow", "\351\235\231\346\200\201P", nullptr));
        lineEdit_I_H->setPlaceholderText(QCoreApplication::translate("MainWindow", "I", nullptr));
        lineEdit_P_H_2->setInputMask(QString());
        lineEdit_P_H_2->setText(QString());
        lineEdit_P_H_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\212\250\346\200\201P", nullptr));
        lineEdit_I_H_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "I", nullptr));
        lineEdit_D_H_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "D", nullptr));
        pushButton_setPID_H->setText(QCoreApplication::translate("MainWindow", "PID", nullptr));
        lineEdit_speed_H->setText(QCoreApplication::translate("MainWindow", "7200", nullptr));
        lineEdit_speed_H->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\227\213\350\275\254\351\200\237\345\272\246 (\350\247\222\347\247\222)", nullptr));
        move_H->setText(QCoreApplication::translate("MainWindow", "\346\227\213\350\275\254", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\271\205\345\200\274", nullptr));
        sine_mag_H->setPlaceholderText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\351\242\221\347\216\207", nullptr));
        sine_freq_H->setPlaceholderText(QString());
        sine_H->setText(QCoreApplication::translate("MainWindow", "\346\255\243\345\274\246\350\267\237\350\270\252", nullptr));
        lineEdit_setspeed_H->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\256\232\351\200\237\351\200\237\345\272\246\350\256\276\347\275\256", nullptr));
        setSpeed_H->setText(QCoreApplication::translate("MainWindow", "\345\256\232\351\200\237\350\267\237\350\270\252", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\347\220\206\350\256\272\344\275\215\347\275\256(\350\247\222\347\247\222)", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\350\257\257\345\267\256(\350\247\222\347\247\222)", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\256\236\351\231\205\344\275\215\347\275\256(\350\247\222\347\247\222)", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246(\350\247\222\347\247\222)", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "RMS(\350\247\222\347\247\222)", nullptr));
        stop_showH->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\347\224\273\345\233\276", nullptr));
        enable_H->setText(QCoreApplication::translate("MainWindow", "\344\275\277\350\203\275", nullptr));
        stop_H->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\350\277\220\345\212\250", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\226\271\344\275\215\350\275\264", nullptr));
        lineEdit_speed_AZ->setText(QCoreApplication::translate("MainWindow", "36000", nullptr));
        lineEdit_speed_AZ->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\227\213\350\275\254\351\200\237\345\272\246 (\350\247\222\347\247\222)", nullptr));
        move_AZ->setText(QCoreApplication::translate("MainWindow", "\346\227\213\350\275\254", nullptr));
        lineEdit_D_AZ->setPlaceholderText(QCoreApplication::translate("MainWindow", "D", nullptr));
        lineEdit_P_AZ->setInputMask(QString());
        lineEdit_P_AZ->setText(QString());
        lineEdit_P_AZ->setPlaceholderText(QCoreApplication::translate("MainWindow", "P", nullptr));
        lineEdit_I_AZ->setPlaceholderText(QCoreApplication::translate("MainWindow", "I", nullptr));
        lineEdit_P_AZ_2->setInputMask(QString());
        lineEdit_P_AZ_2->setText(QString());
        lineEdit_P_AZ_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "P", nullptr));
        lineEdit_I_AZ_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "I", nullptr));
        lineEdit_D_AZ_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "D", nullptr));
        pushButton_setPID_AZ->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256PID", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\271\205\345\200\274", nullptr));
        sine_mag_AZ->setPlaceholderText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "\351\242\221\347\216\207", nullptr));
        sine_freq_AZ->setPlaceholderText(QString());
        sine_AZ->setText(QCoreApplication::translate("MainWindow", "\346\255\243\345\274\246\350\267\237\350\270\252", nullptr));
        lineEdit_setspeed_AZ->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\256\232\351\200\237\351\200\237\345\272\246\350\256\276\347\275\256", nullptr));
        setSpeed_AZ->setText(QCoreApplication::translate("MainWindow", "\345\256\232\351\200\237\350\267\237\350\270\252", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246(\350\247\222\347\247\222)", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\350\257\257\345\267\256(\350\247\222\347\247\222)", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\347\220\206\350\256\272\344\275\215\347\275\256(\350\247\222\347\247\222)", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\256\236\351\231\205\344\275\215\347\275\256(\350\247\222\347\247\222)", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "RMS(\350\247\222\347\247\222)", nullptr));
        stop_showAZ->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\347\224\273\345\233\276", nullptr));
        enable_AZ->setText(QCoreApplication::translate("MainWindow", "\344\275\277\350\203\275", nullptr));
        stop_AZ->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
