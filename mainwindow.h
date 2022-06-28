#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLabel>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include "udpthread.h"
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QSettings>
#include <QCloseEvent>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QLineSeries;
class QAreaSeries;
class QValueAxis;
class QBarSeries;
class QBarSet;
class QScatterSeries;
class QStackedBarSeries;
class QGraphicsScene;
QT_CHARTS_END_NAMESPACE

class Callout;

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

  private:
    QThread* threadUdp;
    udpThread *MyUdp;
    QFile file;
    bool bsave;
    int len = 20;
    QList<float> dataList;
    QChart* chart = nullptr;
    void initGraphic_H();
    void initGraphic_AZ();

    QLineSeries *series_RMS_H;
//    QSplineSeries *series_RMS_H;
    QScatterSeries *scatter_RMS_H;
    QLineSeries *series_set_H;
    QLineSeries *series_actual_H;
    QAreaSeries *areaSeries_H;
    QStackedBarSeries *series_H;
    QBarSet *error_plus_H ;
    QBarSet *error_minus_H ;
    QValueAxis *m_axisX_H;
    QValueAxis *m_axisY_red_H;
    QValueAxis *m_axisY_blue_H;
    QValueAxis *m_axisY_white_H;
    QValueAxis *m_axisY_green_H;


    QSplineSeries *series_RMS_AZ;
    QScatterSeries *scatter_RMS_AZ;
    QLineSeries *series_set_AZ;
    QLineSeries *series_actual_AZ;
    QAreaSeries *areaSeries_AZ;
    QStackedBarSeries *series_AZ;
    QBarSet *error_plus_AZ ;
    QBarSet *error_minus_AZ ;
    QValueAxis *m_axisX_AZ;
    QValueAxis *m_axisY_red_AZ;
    QValueAxis *m_axisY_blue_AZ;
    QValueAxis *m_axisY_white_AZ;
    QValueAxis *m_axisY_green_AZ;


    Callout *m_tooltip;
    QList<Callout *> m_callouts;

    double CurrAZ, CurrH;
    QSpinBox    *mySpinbox;
    QSlider* mySlider;
    QPushButton* pBtnStsConnect;
    QPushButton* pBtnRotateAll;
    QPushButton* pBtnEnableAll;
    QPushButton* pBtnStopAll;
    QPushButton* pBtnStsStop;
    QPushButton* pBtnSave;
    QLabel* preLab;
    QLabel* timeLab1;
    QLabel* timeLab2;
    QLabel* Hz1Lab;
    QLabel* Hz2Lab;
    QLabel* labelPeriod;

  signals:
    void udpsend(QByteArray ba);

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  public slots:
    void keepCallout();
    void tooltip(QPointF point, bool state);

  private slots:
//自定义槽函数
    void dataready();
    void graphDataReady();
    void legendMarkerClicked(); //图例单击
    void handleTimeout();
    void slot_stsbtn_clicked();

    void on_pushButton_clicked();
    void on_pBtnSave_clicked();
    void on_enable_H_clicked();

    void on_stop_H_clicked();

    void on_enable_AZ_clicked();

    void on_stop_AZ_clicked();

    void on_enable_ALL_clicked();

    void on_stop_ALL_clicked();

    void on_move_H_clicked();


    void on_move_AZ_clicked();

    void on_move_ALL_clicked();


    void on_setSpeed_H_clicked();

    void on_setSpeed_AZ_clicked();

    void on_pushButton_setPID_H_clicked();

    void on_pushButton_setPID_AZ_clicked();



    void on_verticalSlider_valueChanged1(int value);

    void on_spinBox_valueChanged1(int arg1);

    void on_stop_showH_clicked();


  private:
    Ui::MainWindow *ui;

  protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
