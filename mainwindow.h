#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include    <QUdpSocket>
#include    <QLabel>
#include <QtCharts/QChart>
#include <QtCore/QTimer>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

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
    int len = 20;
    QList<float> dataList;
    QChart* chart = nullptr;
    QLabel  *LabSocketState;//socket状态显示标签
    QUdpSocket  *udpSocket;//
    QString getLocalIP();//获取本机IP地址
    void initGraphic();//获取本机IP地址
    QTimer m_timer;
    QSplineSeries *series_RMS;
    QScatterSeries *scatter_RMS;
    QLineSeries *series_set;
    QLineSeries *series_actual;
    QAreaSeries *areaSeries;
    QStackedBarSeries *series;
    QBarSet *error_plus ;
    QBarSet *error_minus ;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY_red;
    QValueAxis *m_axisY_blue;
    QValueAxis *m_axisY_white;
    QValueAxis *m_axisY_green;
    QValueAxis *m_axisY4;
    Callout *m_tooltip;
    QList<Callout *> m_callouts;
  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  public slots:
//    void handleTimeout();

    void keepCallout();
    void tooltip(QPointF point, bool state);

  private slots:
//自定义槽函数
    void legendMarkerClicked(); //图例单击
    void handleTimeout();
    void    onSocketStateChange(QAbstractSocket::SocketState socketState);
    void    onSocketReadyRead();//读取socket传入的数据
//
    void on_actStart_triggered();

    void on_actStop_triggered();

    void on_actClear_triggered();

    void on_btnSend_clicked();

    void on_actHostInfo_triggered();

    void on_btnBroadcast_clicked();
    void on_pushButton_clicked();

  private:
    Ui::MainWindow *ui;
  protected:


};

#endif // MAINWINDOW_H
