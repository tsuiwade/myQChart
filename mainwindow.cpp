#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts/QChart>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QAbstractAxis>
//#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

int  TickCount = 20;
int POINT_NUM = 50;

unsigned int BLEndianUint32(unsigned int value) {
    return ((value & 0x000000FF) << 24) | ((value & 0x0000FF00) << 8) |
           ((value & 0x00FF0000) >> 8) | ((value & 0xFF000000) >> 24);
}
unsigned int BLEndianUint16(unsigned int value) {
    return ((value & 0x00FF) << 8) | ((value & 0xFF00) >> 8);
}

void MainWindow::initGraphic_AZ() {
    m_axisX_AZ = new QValueAxis();
    m_axisY_red_AZ = new QValueAxis();
    m_axisY_blue_AZ = new QValueAxis();
    m_axisY_white_AZ = new QValueAxis();
    m_axisY_green_AZ = new QValueAxis();
    m_axisX_AZ->setTickCount(TickCount);
    m_axisX_AZ->setLabelFormat("%d");

    m_axisY_red_AZ->setLabelsColor(QColor(255, 0, 0, 220));
    m_axisY_blue_AZ->setLabelsColor(QColor(0, 230, 230, 255));
    m_axisY_white_AZ->setLabelsColor(QColor(255, 255, 255, 240));
    m_axisY_green_AZ->setLabelsColor(QColor(0, 255, 0, 240));

    chart_AZ->setTitle(tr("方位轴参数曲线"));
    chart_AZ->setTheme(QChart::ChartTheme::ChartThemeDark);
    chart_AZ->setAnimationOptions(QChart::AnimationOption::NoAnimation);
    chart_AZ->legend()->setAlignment(Qt::AlignBottom);

    //    QObject::connect(&m_timer, &QTimer::timeout, this,
    //    m_timer.setInterval(200);
    //    m_timer.start();

    series_RMS_AZ = new QLineSeries(this);
    series_RMS_AZ->setName(" RMS ");

    scatter_RMS_AZ = new QScatterSeries(this);
    scatter_RMS_AZ->setName(" scatter_RMS_AZ ");
    scatter_RMS_AZ->setMarkerShape(QScatterSeries::MarkerShapeCircle); //圆形的点
    scatter_RMS_AZ->setBrush(QColor(255, 255, 255)); //离散点边框颜色
    scatter_RMS_AZ->setMarkerSize(2);                //离散点大小

    series_set_AZ = new QLineSeries(this);
    series_set_AZ->setName("设定位置/角秒");
    series_actual_AZ = new QLineSeries(this);
    series_actual_AZ->setName("实际位置/角秒");
    areaSeries_AZ = new QAreaSeries(series_set_AZ, series_actual_AZ);
    areaSeries_AZ->setName("位置相对关系");
    series_RMS_AZ->setPointsVisible(true);

    QLinearGradient gradient(QPointF(0, 0), QPointF(1, 0));
    gradient.setColorAt(0.0, QColor(0, 206, 209, 100));
    gradient.setColorAt(1.0, QColor(0, 255, 255, 100));
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    areaSeries_AZ->setBrush(gradient);
    areaSeries_AZ->setBorderColor(QColor(0, 230, 230, 100));

    QPen pen_RMS(Qt::white); // white
    pen_RMS.setWidth(3);
    series_RMS_AZ->setPen(pen_RMS);

    error_plus_AZ = new QBarSet("误差(正)");
    error_plus_AZ->setColor(QColor(200, 20, 20, 100));
    error_plus_AZ->setBorderColor(QColor(200, 20, 20, 255));
    error_minus_AZ = new QBarSet("误差(负)");
    error_minus_AZ->setColor(QColor(20, 200, 20, 100));
    error_minus_AZ->setBorderColor(QColor(20, 200, 20, 255));
    series_AZ = new QStackedBarSeries();
    series_AZ->append(error_plus_AZ);
    series_AZ->append(error_minus_AZ);
    series_AZ->setBarWidth(0.5);

    QPen pen_series_set(QColor(0, 230, 230, 100));
    pen_series_set.setWidth(3);
    series_set_AZ->setPen(pen_series_set);

    //    QLinearGradient lineGradient;
    //    lineGradient.setStart(QPointF(0, 0));
    //    lineGradient.setFinalStop(QPointF(1, 0));
    //    lineGradient.setColorAt(0.0, QColor(35, 182, 230, 255));
    //    lineGradient.setColorAt(1.0, QColor(2, 211, 154, 255));
    //    lineGradient.setCoordinateMode(QGradient::StretchToDeviceMode);
    //    series_actual_AZ->setPen(QPen(QBrush(lineGradient), 3));

    QPen pen_series_actual(QColor(0, 230, 230, 255));
    pen_series_actual.setWidth(3);
    series_actual_AZ->setPen(pen_series_actual);

    QFont font1("Times New Roman", 16);
    font1.setBold(true);
    chart_AZ->setTitleFont(font1);
    QFont font("宋体", 12);
    font1.setBold(true);
    chart_AZ->legend()->setFont(font);
    font.setPointSize(9);
    font.setBold(true);
    m_axisY_red_AZ->setLabelsFont(font);
    m_axisY_blue_AZ->setLabelsFont(font);
    m_axisY_white_AZ->setLabelsFont(font);
    m_axisY_green_AZ->setLabelsFont(font);

    //    初始化data

    dataList = udpThread::TargetAZList;
    for (int i = 0; i < dataList.length(); i++) {
        series_RMS_AZ->append(i, dataList.at(i));
        scatter_RMS_AZ->append(i, dataList.at(i));
        series_set_AZ->append(i, dataList.at(i));
        series_actual_AZ->append(i, dataList.at(i));
        error_plus_AZ->append(0);
        error_minus_AZ->append(0);
        series_AZ->append(error_plus_AZ);
        series_AZ->append(error_minus_AZ);
    }

    chart_AZ->addSeries(series_AZ);
    chart_AZ->addSeries(series_RMS_AZ);
    chart_AZ->addSeries(scatter_RMS_AZ);
    chart_AZ->addSeries(series_set_AZ);
    chart_AZ->addSeries(series_actual_AZ);
    chart_AZ->addSeries(areaSeries_AZ);

    chart_AZ->addAxis(m_axisX_AZ, Qt::AlignBottom);
    chart_AZ->addAxis(m_axisY_red_AZ, Qt::AlignLeft);
    chart_AZ->addAxis(m_axisY_blue_AZ, Qt::AlignRight);
    chart_AZ->addAxis(m_axisY_white_AZ, Qt::AlignRight);
    chart_AZ->addAxis(m_axisY_green_AZ, Qt::AlignLeft);

    series_AZ->attachAxis(m_axisX_AZ);
    series_AZ->attachAxis(m_axisY_red_AZ);
    series_RMS_AZ->attachAxis(m_axisX_AZ);
    series_RMS_AZ->attachAxis(m_axisY_white_AZ);
    scatter_RMS_AZ->attachAxis(m_axisX_AZ);
    scatter_RMS_AZ->attachAxis(m_axisY_white_AZ);
    series_set_AZ->attachAxis(m_axisX_AZ);
    series_set_AZ->attachAxis(m_axisY_blue_AZ);
    series_actual_AZ->attachAxis(m_axisX_AZ);
    series_actual_AZ->attachAxis(m_axisY_blue_AZ);
    areaSeries_AZ->attachAxis(m_axisX_AZ);
    areaSeries_AZ->attachAxis(m_axisY_blue_AZ);

    m_axisX_AZ->setRange(0, POINT_NUM);
    m_axisY_white_AZ->setRange(-5, 10);
    m_axisY_red_AZ->setRange(-5, 10);
    m_axisY_green_AZ->setRange(-5, 10);
    m_axisY_blue_AZ->setRange(-10, 20);

    ui->graphicsView_2->setChart(chart_AZ);
    ui->graphicsView_2->setRenderHint(QPainter::Antialiasing);

    chart_AZ->legend()->markers(scatter_RMS_AZ)[0]->setVisible(false);

    foreach (QLegendMarker *marker, chart_AZ->legend()->markers()) {
        marker->setShape(QLegend::MarkerShapeCircle);
        QObject::disconnect(marker, SIGNAL(clicked()), this,
                            SLOT(legendMarkerClicked()));
        QObject::connect(marker, SIGNAL(clicked()), this,
                         SLOT(legendMarkerClicked()));
    }
}

void MainWindow::initGraphic_H() {
    m_axisX_H = new QValueAxis();
    m_axisY_red_H = new QValueAxis();
    m_axisY_blue_H = new QValueAxis();
    m_axisY_white_H = new QValueAxis();
    m_axisY_green_H = new QValueAxis();
    m_axisX_H->setTickCount(TickCount);
    m_axisX_H->setLabelFormat("%d");

    m_axisY_red_H->setLabelsColor(QColor(255, 0, 0, 220));
    m_axisY_blue_H->setLabelsColor(QColor(0, 230, 230, 255));
    m_axisY_white_H->setLabelsColor(QColor(255, 255, 255, 240));
    m_axisY_green_H->setLabelsColor(QColor(0, 255, 0, 240));

    chart->setTitle(tr("高度轴参数曲线"));
    chart->setTheme(QChart::ChartTheme::ChartThemeDark);
    chart->setAnimationOptions(QChart::AnimationOption::NoAnimation);
    chart->legend()->setAlignment(Qt::AlignBottom);

    //    QObject::connect(&m_timer, &QTimer::timeout, this,
    //    m_timer.setInterval(200);
    //    m_timer.start();

    series_RMS_H = new QLineSeries(this);
    series_RMS_H->setName(" RMS ");

    scatter_RMS_H = new QScatterSeries(this);
    scatter_RMS_H->setName(" scatter_RMS_H ");
    scatter_RMS_H->setMarkerShape(QScatterSeries::MarkerShapeCircle); //圆形的点
    scatter_RMS_H->setBrush(QColor(255, 255, 255)); //离散点边框颜色
    scatter_RMS_H->setMarkerSize(2);                //离散点大小

    series_set_H = new QLineSeries(this);
    series_set_H->setName("设定位置/角秒");
    series_actual_H = new QLineSeries(this);
    series_actual_H->setName("实际位置/角秒");
    areaSeries_H = new QAreaSeries(series_set_H, series_actual_H);
    areaSeries_H->setName("位置相对关系");
    series_RMS_H->setPointsVisible(true);
    //    series_set_H->setPointsVisible(true);
    //    series_actual_H->setPointsVisible(true);

    QLinearGradient gradient(QPointF(0, 0), QPointF(1, 0));
    gradient.setColorAt(0.0, QColor(0, 206, 209, 100));
    gradient.setColorAt(1.0, QColor(0, 255, 255, 100));
    //    gradient.setColorAt(0.0, QColor(35, 182, 230, 100));
    //    gradient.setColorAt(1.0, QColor(2, 211, 154, 100));
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    areaSeries_H->setBrush(gradient);
    areaSeries_H->setBorderColor(QColor(0, 230, 230, 100));

    QPen pen_RMS(Qt::white); // white
    pen_RMS.setWidth(3);
    series_RMS_H->setPen(pen_RMS);

    error_plus_H = new QBarSet("误差(正)");
    error_plus_H->setColor(QColor(200, 20, 20, 100));
    error_plus_H->setBorderColor(QColor(200, 20, 20, 255));
    error_minus_H = new QBarSet("误差(负)");
    error_minus_H->setColor(QColor(20, 200, 20, 100));
    error_minus_H->setBorderColor(QColor(20, 200, 20, 255));
    series_H = new QStackedBarSeries();
    series_H->append(error_plus_H);
    series_H->append(error_minus_H);
    series_H->setBarWidth(0.5);

    QPen pen_series_set(QColor(0, 230, 230, 100));
    pen_series_set.setWidth(3);
    series_set_H->setPen(pen_series_set);

    //    QLinearGradient lineGradient;
    //    lineGradient.setStart(QPointF(0, 0));
    //    lineGradient.setFinalStop(QPointF(1, 0));
    //    lineGradient.setColorAt(0.0, QColor(35, 182, 230, 255));
    //    lineGradient.setColorAt(1.0, QColor(2, 211, 154, 255));
    //    lineGradient.setCoordinateMode(QGradient::StretchToDeviceMode);
    //    series_actual_H->setPen(QPen(QBrush(lineGradient), 3));

    QPen pen_series_actual(QColor(0, 230, 230, 255));
    pen_series_actual.setWidth(3);
    series_actual_H->setPen(pen_series_actual);

    QFont font1("Times New Roman", 16);
    font1.setBold(true);
    chart->setTitleFont(font1);
    QFont font("宋体", 12);
    font1.setBold(true);
    chart->legend()->setFont(font);
    font.setPointSize(9);
    font.setBold(true);
    m_axisY_red_H->setLabelsFont(font);
    m_axisY_blue_H->setLabelsFont(font);
    m_axisY_white_H->setLabelsFont(font);
    m_axisY_green_H->setLabelsFont(font);

    //    初始化data
    dataList = udpThread::TargetAZList;
    for (int i = 0; i < dataList.length(); i++) {
        series_RMS_H->append(i, dataList.at(i));
        scatter_RMS_H->append(i, dataList.at(i));
        series_set_H->append(i, dataList.at(i));
        series_actual_H->append(i, dataList.at(i));
        error_plus_H->append(0);
        error_minus_H->append(0);
        series_H->append(error_plus_H);
        series_H->append(error_minus_H);
    }

    chart->addSeries(series_H);
    chart->addSeries(series_RMS_H);
    chart->addSeries(scatter_RMS_H);
    chart->addSeries(series_set_H);
    chart->addSeries(series_actual_H);
    chart->addSeries(areaSeries_H);

    chart->addAxis(m_axisX_H, Qt::AlignBottom);
    chart->addAxis(m_axisY_red_H, Qt::AlignLeft);
    chart->addAxis(m_axisY_blue_H, Qt::AlignRight);
    chart->addAxis(m_axisY_white_H, Qt::AlignRight);
    chart->addAxis(m_axisY_green_H, Qt::AlignLeft);

    series_H->attachAxis(m_axisX_H);
    series_H->attachAxis(m_axisY_red_H);
    series_RMS_H->attachAxis(m_axisX_H);
    series_RMS_H->attachAxis(m_axisY_white_H);
    scatter_RMS_H->attachAxis(m_axisX_H);
    scatter_RMS_H->attachAxis(m_axisY_white_H);
    series_set_H->attachAxis(m_axisX_H);
    series_set_H->attachAxis(m_axisY_blue_H);
    series_actual_H->attachAxis(m_axisX_H);
    series_actual_H->attachAxis(m_axisY_blue_H);
    areaSeries_H->attachAxis(m_axisX_H);
    areaSeries_H->attachAxis(m_axisY_blue_H);

    m_axisX_H->setRange(0, POINT_NUM);
    m_axisY_white_H->setRange(-5, 10);
    m_axisY_red_H->setRange(-5, 10);
    m_axisY_green_H->setRange(-5, 10);
    m_axisY_blue_H->setRange(-10, 20);

    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    chart->legend()->markers(scatter_RMS_H)[0]->setVisible(false);

    foreach (QLegendMarker *marker, chart->legend()->markers()) {
        marker->setShape(QLegend::MarkerShapeCircle);
        QObject::disconnect(marker, SIGNAL(clicked()), this,
                            SLOT(legendMarkerClicked()));
        QObject::connect(marker, SIGNAL(clicked()), this,
                         SLOT(legendMarkerClicked()));
    }
}

void MainWindow::on_pBtnSave_clicked() {
    if (pBtnSave->text() == "开始保存误差数据") {
        pBtnSave->setText("完成保存误差数据");
        QString filePath = QCoreApplication::applicationDirPath();
        QDateTime time = QDateTime::currentDateTime();
        QString strtime;
        strtime = time.toString("yyyyMMddhhmmss");
        QString fileName = filePath + "/" + strtime + ".csv";
        file.setFileName(fileName);
        file.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);

        QString str =
            QStringLiteral("time/"
                           "s,RMS_H,RMS_AZ,error_H,error_AZ,speed_H,speed_AZ,"
                           "actual_H,actual_AZ,target_H,target_AZ\n");
        file.write(str.toLocal8Bit());
        bsave = true;
    } else {
        pBtnSave->setText("开始保存误差数据");
        file.close();
        bsave = false;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    bsave = 0;
    chart = new QChart();
    chart_AZ = new QChart();
    MyUdp = new udpThread;
    initGraphic_H();
    initGraphic_AZ();


    threadUdp = new QThread(this);
    MyUdp->moveToThread(threadUdp);
    connect(threadUdp, &QThread::started, MyUdp, &udpThread::run);
    connect(threadUdp, &QThread::finished, MyUdp, &udpThread::closeudp);
    connect(MyUdp, &udpThread::dataready, this, &MainWindow::dataready);
    connect(MyUdp, &udpThread::graphDataReady, this, &MainWindow::graphDataReady);
    connect(this, &MainWindow::udpsend, MyUdp, &udpThread::writefun);

    threadUdp->start();
    preLab = new QLabel();
    timeLab1 = new QLabel("时间/s: ");
    timeLab2 = new QLabel();
    timeLab2->setFixedSize(80, 20);
    Hz1Lab = new QLabel();
    Hz1Lab->setFixedSize(40, 30);
    Hz2Lab = new QLabel("Hz");
    Hz2Lab->setFixedSize(100, 30);
    preLab->setFixedSize(100, 20);
    labelPeriod = new QLabel();
    labelPeriod->setText("周期");
    labelPeriod->setFixedSize(50, 20);
    mySpinbox = new QSpinBox();
    mySpinbox->setValue(1);
    mySpinbox->setMinimum(1);
    mySpinbox->setMaximum(100);
    mySlider = new QSlider();
    mySlider->setOrientation(Qt::Orientation::Horizontal);
    mySlider->setFixedSize(200, 30);
    mySlider->setTickPosition(QSlider::TickPosition::TicksBothSides);
    mySlider->setMinimum(1);
    mySlider->setMaximum(100);
    mySlider->setSingleStep(1);
    mySlider->setValue(1);
    mySlider->setSliderPosition(1);
    pBtnStsConnect = new QPushButton();
    pBtnRotateAll = new QPushButton();
    pBtnStopAll = new QPushButton();
    pBtnEnableAll = new QPushButton();
    pBtnSave = new QPushButton();
    pBtnStsConnect->setFixedSize(88, 20);
    pBtnRotateAll->setFixedSize(88, 20);
    pBtnStopAll->setFixedSize(88, 20);
    pBtnEnableAll->setFixedSize(88, 20);
    pBtnSave->setFixedSize(128, 20);
    pBtnStsConnect->setFlat(true);
    pBtnRotateAll->setFlat(true);
    pBtnStopAll->setFlat(true);
    pBtnEnableAll->setFlat(true);
    pBtnSave->setFlat(true);
    pBtnStsConnect->setText("软件复位");
    pBtnRotateAll->setText("同时旋转");
    pBtnStopAll->setText("同时停止");
    pBtnEnableAll->setText("同时使能");
    pBtnSave->setText("开始保存误差数据");

    ui->statusBar->addWidget(preLab);
    ui->statusBar->addWidget(mySlider);
    ui->statusBar->addWidget(mySpinbox);
    ui->statusBar->addWidget(labelPeriod);
    ui->statusBar->addWidget(Hz1Lab);
    ui->statusBar->addWidget(Hz2Lab);
    ui->statusBar->addWidget(pBtnEnableAll);
    ui->statusBar->addWidget(pBtnRotateAll);
    ui->statusBar->addWidget(pBtnStopAll);
    ui->statusBar->addWidget(pBtnSave);
    ui->statusBar->addPermanentWidget(timeLab1);
    ui->statusBar->addPermanentWidget(timeLab2);
    ui->statusBar->addPermanentWidget(pBtnStsConnect);
    connect(this->mySlider, SIGNAL(valueChanged(int)), this,
            SLOT(on_verticalSlider_valueChanged1(int)));
    connect(this->mySpinbox, SIGNAL(valueChanged(int)), this,
            SLOT(on_spinBox_valueChanged1(int)));
    connect(this->pBtnStsConnect, &QPushButton::clicked, this,
            &MainWindow::slot_stsbtn_clicked);
    connect(this->pBtnSave, &QPushButton::clicked, this,
            &MainWindow::on_pBtnSave_clicked);
    connect(this->pBtnRotateAll, &QPushButton::clicked, this,
            &MainWindow::on_move_ALL_clicked);
    connect(this->pBtnEnableAll, &QPushButton::clicked, this,
            &MainWindow::on_enable_ALL_clicked);
    connect(this->pBtnStopAll, &QPushButton::clicked, this,
            &MainWindow::on_stop_ALL_clicked);
    QString fileName = "qttconfig.ini";
    QSettings *set = new QSettings(fileName, QSettings::IniFormat);
    set->setIniCodec("");
    set->beginGroup("AppConfig");
    ui->lineEdit_P_H->setText(set->value("lineEdit_P_H").toString());
    ui->lineEdit_I_H->setText(set->value("lineEdit_I_H").toString());
    ui->lineEdit_D_H->setText(set->value("lineEdit_D_H").toString());
    ui->lineEdit_P_H_2->setText(set->value("lineEdit_P_H_2").toString());
    ui->lineEdit_I_H_2->setText(set->value("lineEdit_I_H_2").toString());
    ui->lineEdit_D_H_2->setText(set->value("lineEdit_D_H_2").toString());
    ui->lineEdit_P_AZ->setText(set->value("lineEdit_P_AZ").toString());
    ui->lineEdit_I_AZ->setText(set->value("lineEdit_I_AZ").toString());
    ui->lineEdit_D_AZ->setText(set->value("lineEdit_D_AZ").toString());
    ui->lineEdit_P_AZ_2->setText(set->value("lineEdit_P_AZ_2").toString());
    ui->lineEdit_I_AZ_2->setText(set->value("lineEdit_I_AZ_2").toString());
    ui->lineEdit_D_AZ_2->setText(set->value("lineEdit_D_AZ_2").toString());
    ui->lineEdit_speed_H->setText(set->value("lineEdit_speed_H").toString());
    ui->sine_mag_H->setText(set->value("sine_mag_H").toString());
    ui->sine_mag_AZ->setText(set->value("sine_mag_AZ").toString());
    ui->sine_freq_H->setText(set->value("sine_freq_H").toString());
    ui->sine_freq_AZ->setText(set->value("sine_freq_AZ").toString());
    ui->lineEdit_setspeed_H->setText(set->value("lineEdit_setspeed_H").toString());
    ui->lineEdit_speed_AZ->setText(set->value("lineEdit_speed_AZ").toString());
    ui->lineEdit_setspeed_AZ->setText(set->value("lineEdit_setspeed_AZ").toString());
    this->mySpinbox->setValue(set->value("spinBox").toInt());
    set->endGroup();
}
void MainWindow::slot_stsbtn_clicked() {
    QByteArray ba(2, 0);
    ba[0] = 'F';
    ba[1] = 'W';

    emit udpsend(ba);
}

void MainWindow::closeEvent(QCloseEvent *event) {
    QString fileName = "qttconfig.ini";
    QSettings *set = new QSettings(fileName, QSettings::IniFormat);
    set->setIniCodec("UTF-8");
    set->beginGroup("AppConfig");
    set->setValue("lineEdit_P_H", ui->lineEdit_P_H->text());
    set->setValue("lineEdit_I_H", ui->lineEdit_I_H->text());
    set->setValue("lineEdit_D_H", ui->lineEdit_D_H->text());
    set->setValue("lineEdit_P_H_2", ui->lineEdit_P_H_2->text());
    set->setValue("lineEdit_I_H_2", ui->lineEdit_I_H_2->text());
    set->setValue("lineEdit_D_H_2", ui->lineEdit_D_H_2->text());
    set->setValue("lineEdit_P_AZ", ui->lineEdit_P_AZ->text());
    set->setValue("lineEdit_I_AZ", ui->lineEdit_I_AZ->text());
    set->setValue("lineEdit_D_AZ", ui->lineEdit_D_AZ->text());
    set->setValue("lineEdit_P_AZ_2", ui->lineEdit_P_AZ_2->text());
    set->setValue("lineEdit_I_AZ_2", ui->lineEdit_I_AZ_2->text());
    set->setValue("lineEdit_D_AZ_2", ui->lineEdit_D_AZ_2->text());
    set->setValue("lineEdit_speed_H", ui->lineEdit_speed_H->text());
    set->setValue("lineEdit_setspeed_H", ui->lineEdit_setspeed_H->text());
    set->setValue("sine_mag_AZ", ui->sine_mag_AZ->text());
    set->setValue("sine_freq_H", ui->sine_freq_H->text());
    set->setValue("sine_mag_H", ui->sine_mag_H->text());
    set->setValue("lineEdit_speed_AZ", ui->lineEdit_speed_AZ->text());
    set->setValue("sine_freq_AZ", ui->sine_freq_AZ->text());
    set->setValue("lineEdit_setspeed_AZ", ui->lineEdit_setspeed_AZ->text());
    set->setValue("spinBox", this->mySpinbox->value());
    set->endGroup();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::graphDataReady() {
    int maxHList = 0, minHList = 0, maxAZList = 0, minAZList = 0;
    double maxRMSH = 0, minRMSH = 0, maxRMSAZ = 0, minRMSAZ = 0;
    int maxErrH = 1, minErrH = -1, maxErrAZ = 1, minErrAZ = -1;
    int lenAZ = udpThread::ErrAZList.size();

    for (int i = 0; i < lenAZ; i++) {

        series_set_H->replace(i, i, udpThread::TargetHList.at(i));
        series_actual_H->replace(i, i, udpThread::CurrHList.at(i));
        series_RMS_H->replace(i, i, udpThread::RMSHList.at(i));
        scatter_RMS_H->replace(i, i, udpThread::RMSHList.at(i));

        series_set_AZ->replace(i, i, udpThread::TargetAZList.at(i));
        series_actual_AZ->replace(i, i, udpThread::CurrAZList.at(i));
        series_RMS_AZ->replace(i, i, udpThread::RMSAZList.at(i));
        scatter_RMS_AZ->replace(i, i, udpThread::RMSAZList.at(i));
        if (udpThread::TargetHList.at(i) > maxHList)
            maxHList = udpThread::TargetHList.at(i);
        if (udpThread::CurrHList.at(i) > maxHList)
            maxHList = udpThread::CurrHList.at(i);

        if (udpThread::TargetHList.at(i) < minHList)
            minHList = udpThread::TargetHList.at(i);
        if (udpThread::CurrHList.at(i) < minHList)
            minHList = udpThread::CurrHList.at(i);

        if (udpThread::ErrHList.at(i) > 0) {
            error_plus_H->replace(i, udpThread::ErrHList.at(i));
            error_minus_H->replace(i, 0);
        } else {
            error_minus_H->replace(i, udpThread::ErrHList.at(i));
            error_plus_H->replace(i, 0);
        }

        if (udpThread::ErrHList.at(i) < minErrH)
            minErrH = udpThread::ErrHList.at(i);
        if (udpThread::ErrHList.at(i) > maxErrH)
            maxErrH = udpThread::ErrHList.at(i);
        if (udpThread::RMSHList.at(i) > maxRMSH)
            maxRMSH = udpThread::RMSHList.at(i);
        if (udpThread::RMSHList.at(i) < minRMSH)
            minRMSH = udpThread::RMSHList.at(i);
        /*************************************************************/
        if (udpThread::TargetAZList.at(i) > maxAZList)
            maxAZList = udpThread::TargetAZList.at(i);
        if (udpThread::CurrAZList.at(i) > maxAZList)
            maxAZList = udpThread::CurrAZList.at(i);

        if (udpThread::TargetAZList.at(i) < minAZList)
            minAZList = udpThread::TargetAZList.at(i);
        if (udpThread::CurrAZList.at(i) < minAZList)
            minAZList = udpThread::CurrAZList.at(i);

        if (udpThread::ErrAZList.at(i) > 0) {
            error_plus_AZ->replace(i, udpThread::ErrAZList.at(i));
            error_minus_AZ->replace(i, 0);
        } else {
            error_minus_AZ->replace(i, udpThread::ErrAZList.at(i));
            error_plus_AZ->replace(i, 0);
        }

        if (udpThread::ErrAZList.at(i) < minErrAZ)
            minErrAZ = udpThread::ErrAZList.at(i);
        if (udpThread::ErrAZList.at(i) > maxErrAZ)
            maxErrAZ = udpThread::ErrAZList.at(i);
        if (udpThread::RMSAZList.at(i) > maxRMSAZ)
            maxRMSAZ = udpThread::RMSAZList.at(i);

        if (udpThread::RMSAZList.at(i) < minRMSAZ)
            minRMSAZ = udpThread::RMSAZList.at(i);
    }
    m_axisY_white_H->setRange(minRMSH, maxRMSH);
    m_axisY_blue_H->setRange((int)minHList, (int)maxHList);
    m_axisY_red_H->setRange(minErrH, maxErrH);
    m_axisY_green_H->setRange(minErrH, maxErrH);
    m_axisY_white_AZ->setRange(minRMSAZ, maxRMSAZ);
    m_axisY_blue_AZ->setRange((int)minAZList, (int)maxAZList);
    m_axisY_red_AZ->setRange(minErrAZ, maxErrAZ);
    m_axisY_green_AZ->setRange(minErrAZ, maxErrAZ);
}
void MainWindow::dataready() {
    if (udpThread::HEnable && ui->enable_H->text() == "使能")
        ui->enable_H->setText("失能");
    if (!udpThread::HEnable && ui->enable_H->text() == "失能")
        ui->enable_H->setText("使能");
    if (udpThread::AZEnable && ui->enable_AZ->text() == "使能")
        ui->enable_AZ->setText("失能");
    if (!udpThread::AZEnable && ui->enable_AZ->text() == "失能")
        ui->enable_AZ->setText("使能");
    if (udpThread::HEnable && udpThread::AZEnable &&
            this->pBtnEnableAll->text() == "同时使能")
        this->pBtnEnableAll->setText("同时失能");
    if (!udpThread::HEnable && !udpThread::AZEnable &&
            this->pBtnEnableAll->text() == "同时失能")
        this->pBtnEnableAll->setText("同时使能");
    timeLab2->setText(QString::number(udpThread::datatime));
    ui->error_H->setText(QString::number(udpThread::ErrH, 'f', 1));
    ui->error_AZ->setText(QString::number(udpThread::ErrAZ, 'f', 1));
    ui->speed_H->setText(QString::number(udpThread::speed_H));
    ui->speed_AZ->setText(QString::number(udpThread::speed_AZ));
    ui->actual_H->setText(QString::number(udpThread::CurrHCount / 10.0, 'f', 1));
    ui->actual_AZ->setText(
        QString::number(udpThread::CurrAZCount / 10.0, 'f', 1));
    ui->target_H->setText(QString::number(udpThread::TargetH, 'f', 1));
    ui->target_AZ->setText(QString::number(udpThread::TargetAZ, 'f', 1));
    ui->RMS_H->setText(QString::number(udpThread::RMSH, 'f', 2));
    ui->RMS_AZ->setText(QString::number(udpThread::RMSAZ, 'f', 2));

    if (bsave) {
        QString RMS_H = QString::number(udpThread::RMSH, 'f', 2);
        QString RMS_AZ = QString::number(udpThread::RMSAZ, 'f', 2);
        QString error_H = QString::number(udpThread::ErrH, 'f', 1);
        QString error_AZ = QString::number(udpThread::ErrAZ, 'f', 1);
        QString speed_H = QString::number(udpThread::speed_H);
        QString speed_AZ = QString::number(udpThread::speed_AZ);
        QString actual_H = QString::number(udpThread::CurrHCount / 10.0, 'f', 1);
        QString actual_AZ = QString::number(udpThread::CurrAZCount / 10.0, 'f', 1);
        QString target_H = QString::number(udpThread::TargetH, 'f', 1);
        QString target_AZ = QString::number(udpThread::TargetAZ, 'f', 1);
        //            QString times = QString::number(udpThread::datatime);
        QString timems = QString::number(
                             udpThread::datatime + (udpThread::datatimems / 1000.0), 'f', 3);
        QString str = timems + ',' + RMS_AZ + ',' + RMS_H + ',' + error_H + ',' +
                      error_AZ + ',' + speed_H + ',' + speed_AZ + ',' + actual_H +
                      ',' + actual_AZ + ',' + target_H + ',' + target_AZ + '\n';
        file.write(str.toLocal8Bit());
        file.flush();
    }
}

void MainWindow::legendMarkerClicked() {

    chart->update();
    chart_AZ->update();

    QLegendMarker *marker = qobject_cast<QLegendMarker *>(sender());
    if (marker == chart->legend()->markers(series_RMS_H)[0]) {
        if (!scatter_RMS_H->isVisible()) {
            scatter_RMS_H->setVisible(true);
            chart->legend()->markers(scatter_RMS_H)[0]->setVisible(false);
        } else
            scatter_RMS_H->setVisible(false);
    }
    if (marker == chart_AZ->legend()->markers(series_RMS_AZ)[0]) {
        if (!scatter_RMS_AZ->isVisible()) {
            scatter_RMS_AZ->setVisible(true);
            chart_AZ->legend()->markers(scatter_RMS_AZ)[0]->setVisible(false);
        } else
            scatter_RMS_AZ->setVisible(false);
    }
    marker->series()->setVisible(!marker->series()->isVisible());
    marker->setVisible(true);
    qreal alpha = 1.0;
    if (!marker->series()->isVisible())
        alpha = 0.5;

    QColor color;
    QBrush brush = marker->labelBrush();
    color = brush.color();
    color.setAlphaF(alpha);
    brush.setColor(color);
    marker->setLabelBrush(brush);

    brush = marker->brush();
    color = brush.color();
    color.setAlphaF(alpha);
    brush.setColor(color);
    marker->setBrush(brush);

    QPen pen = marker->pen();
    color = pen.color();
    color.setAlphaF(alpha);
    pen.setColor(color);
    marker->setPen(pen);
}

void MainWindow::on_enable_H_clicked() {
    QByteArray ba(4, 0);
    ba[0] = 'C';
    ba[1] = 'A';
    ba[2] = 'G';
    if (ui->enable_H->text() == "使能") {
        ba[3] = 'E';
    } else {
        ba[3] = 'D';
    }
    emit udpsend(ba);
}

void MainWindow::on_stop_H_clicked() {
    QByteArray ba(3, 0);
    ba[0] = 'C';
    ba[1] = 'S';
    ba[2] = 'G';
    emit udpsend(ba);
}

void MainWindow::on_enable_AZ_clicked() {
    QByteArray ba(4, 0);
    ba[0] = 'C';
    ba[1] = 'A';
    ba[2] = 'F';
    if (ui->enable_AZ->text() == "使能") {
        ba[3] = 'E';
    } else {
        ba[3] = 'D';
    }
    emit udpsend(ba);
}

void MainWindow::on_stop_AZ_clicked() {
    QByteArray ba(3, 0);
    ba[0] = 'C';
    ba[1] = 'S';
    ba[2] = 'F';
    emit udpsend(ba);
}

void MainWindow::on_enable_ALL_clicked() {
    QByteArray ba(4, 0);
    ba[0] = 'C';
    ba[1] = 'A';
    ba[2] = 'A';
    if (ui->enable_H->text() == "使能") {
        ba[3] = 'E';
    } else {
        ba[3] = 'D';
    }
    emit udpsend(ba);
}

void MainWindow::on_stop_ALL_clicked() {
    QByteArray ba(3, 0);
    ba[0] = 'C';
    ba[1] = 'S';
    ba[2] = 'A';
    emit udpsend(ba);
}

void MainWindow::on_move_H_clicked() {
    QByteArray ba(11, 0);
    ba[0] = 'C';
    ba[1] = 'M';
    ba[2] = 'G';
    int value = ui->lineEdit_speed_H->text().toInt();
    value = BLEndianUint32(value);
    memcpy(ba.data() + 3, &value, 4);
    emit udpsend(ba);
}

void MainWindow::on_move_AZ_clicked() {
    QByteArray ba(11, 0);
    ba[0] = 'C';
    ba[1] = 'M';
    ba[2] = 'F';
    int value = ui->lineEdit_speed_AZ->text().toInt();
    value = BLEndianUint32(value);
    memcpy(ba.data() + 7, &value, 4);
    emit udpsend(ba);
}

void MainWindow::on_move_ALL_clicked() {
    QByteArray ba(11, 0);
    ba[0] = 'C';
    ba[1] = 'M';
    ba[2] = 'A';
    int value1 = ui->lineEdit_speed_AZ->text().toInt();
    int value2 = ui->lineEdit_speed_H->text().toInt();
    value1 = BLEndianUint32(value1);
    memcpy(ba.data() + 7, &value1, 4);
    value2 = BLEndianUint32(value2);
    memcpy(ba.data() + 3, &value2, 4);
    emit udpsend(ba);
}

void MainWindow::on_setSpeed_H_clicked() {
    QByteArray ba(5, 0);
    ba[0] = 'C';
    ba[1] = 'S';
    int value = ui->lineEdit_setspeed_H->text().toShort();
    //    value = BLEndianUint16(value);
    memcpy(ba.data() + 2, &value, 2);
    ba[4] = 'G';
    emit udpsend(ba);

    ba.resize(3);
    ba[0] = 'G';
    ba[1] = 'D';
    ba[2] = 'G';
    emit udpsend(ba);
}

void MainWindow::on_setSpeed_AZ_clicked() {
    QByteArray ba(5, 0);
    ba[0] = 'C';
    ba[1] = 'S';
    int value = ui->lineEdit_setspeed_AZ->text().toShort();
    //   value = BLEndianUint16(value);
    memcpy(ba.data() + 2, &value, 2);
    ba[4] = 'F';
    emit udpsend(ba);

    ba.resize(3);
    ba[0] = 'G';
    ba[1] = 'D';
    ba[2] = 'F';
    emit udpsend(ba);
}

void MainWindow::on_pushButton_setPID_H_clicked() {
    QByteArray ba(14, 0);
    ba[0] = 'S';
    ba[1] = 'Y';
    int value1 = ui->lineEdit_P_H->text().toShort();
    int value2 = ui->lineEdit_I_H->text().toShort();
    int value3 = ui->lineEdit_D_H->text().toShort();
    int value4 = ui->lineEdit_P_H_2->text().toShort();
    int value5 = ui->lineEdit_I_H_2->text().toShort();
    int value6 = ui->lineEdit_D_H_2->text().toShort();

    memcpy(ba.data() + 2, &value1, 2);
    memcpy(ba.data() + 4, &value2, 2);
    memcpy(ba.data() + 6, &value3, 2);
    memcpy(ba.data() + 8, &value4, 2);
    memcpy(ba.data() + 10, &value5, 2);
    memcpy(ba.data() + 12, &value6, 2);
    emit udpsend(ba);
}

void MainWindow::on_pushButton_setPID_AZ_clicked() {
    QByteArray ba(8, 0);
    ba[0] = 'S';
    ba[1] = 'F';
    unsigned short value1 = ui->lineEdit_P_AZ->text().toUShort();
    unsigned short value2 = ui->lineEdit_I_AZ->text().toUShort();
    unsigned short value3 = ui->lineEdit_D_AZ->text().toUShort();
    value1 = BLEndianUint16(value1);
    value2 = BLEndianUint16(value2);
    value3 = BLEndianUint16(value3);
    memcpy(ba.data() + 2, &value1, 2);
    memcpy(ba.data() + 4, &value2, 2);
    memcpy(ba.data() + 6, &value3, 2);
    emit udpsend(ba);
}

void MainWindow::on_spinBox_valueChanged1(int arg1) {
    this->Hz1Lab->setNum(QString::number(50.0 / arg1, 'f', 2).toDouble());
    udpThread::count = arg1;
    this->mySlider->setValue(arg1);
}
void MainWindow::on_verticalSlider_valueChanged1(int value) {
    this->mySpinbox->setValue(value);
}

void MainWindow::on_stop_showH_clicked() {
    if (ui->stop_showH->text() == "停止画图") {
        ui->stop_showH->setText("开始画图");
        MyUdp->listClear();
        udpThread::draw_flag = !udpThread::draw_flag;
    } else {
        ui->stop_showH->setText("停止画图");
        udpThread::draw_flag = !udpThread::draw_flag;
    }
}

void MainWindow::on_sine_H_clicked() {
    QByteArray ba(7, 0);
    ba[0] = 'Z';
    ba[1] = 'X';
    unsigned short value1 = ui->sine_mag_H->text().toUShort();
    unsigned short value2 = ui->sine_freq_H->text().toUShort();
    memcpy(ba.data() + 2, &value1, 2);
    memcpy(ba.data() + 4, &value2, 2);
    ba[6] = 'G';
    emit udpsend(ba);
}

void MainWindow::on_sine_AZ_clicked() {
    QByteArray ba(7, 0);
    ba[0] = 'Z';
    ba[1] = 'X';
    unsigned short value1 = ui->sine_mag_AZ->text().toUShort();
    unsigned short value2 = ui->sine_freq_AZ->text().toUShort();
    memcpy(ba.data() + 2, &value1, 2);
    memcpy(ba.data() + 4, &value2, 2);
    ba[6] = 'F';
    emit udpsend(ba);
}
