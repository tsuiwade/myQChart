#include "mainwindow.h"
#include "ui_mainwindow.h"
#include    <QtNetwork>

#include <QtCharts/QChart>
#include <QtCore/QTimer>
#include    <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>
#include "callout.h"


void MainWindow::initGraphic() {
    m_tooltip = 0;
    m_axisX = new QValueAxis();
    m_axisY_red = new QValueAxis();
    m_axisY_blue = new QValueAxis();
    m_axisY_white = new QValueAxis();
    m_axisY_green = new QValueAxis();
    m_axisX->setTickCount(len + 1);
    m_axisX->setLabelFormat("%d");

    m_axisY_red->setLabelsColor(QColor(255, 0, 0, 220));
    m_axisY_blue->setLabelsColor(QColor(0, 230, 230, 255));
    m_axisY_white->setLabelsColor(QColor(255, 255, 255, 240));
    m_axisY_green->setLabelsColor(QColor(0, 255, 0, 240));

    chart->setTitle(tr("高度轴参数曲线"));
    chart->setTheme(QChart::ChartTheme::ChartThemeDark);
    chart->setAnimationOptions(QChart::AnimationOption::NoAnimation);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QObject::connect(&m_timer, &QTimer::timeout, this, &MainWindow::handleTimeout);
    m_timer.setInterval(200);
    m_timer.start();

    series_RMS = new QSplineSeries(this);
    series_RMS->setName(" RMS ");

    scatter_RMS = new QScatterSeries(this);
    scatter_RMS->setName(" scatter_RMS ");
    scatter_RMS->setMarkerShape(QScatterSeries::MarkerShapeCircle);//圆形的点
    scatter_RMS->setBrush(QColor(255, 255, 255)); //离散点边框颜色
    scatter_RMS->setMarkerSize(5); //离散点大小

    series_set = new QLineSeries(this);
    series_set->setName("设定位置");
    series_actual = new QLineSeries(this);
    series_actual->setName("实际位置");
    areaSeries = new QAreaSeries(series_set, series_actual);
    areaSeries->setName("位置相对关系");
    series_RMS->setPointsVisible(true);
//    series_set->setPointsVisible(true);
//    series_actual->setPointsVisible(true);

    QLinearGradient gradient(QPointF(0, 0), QPointF(1, 0));
    gradient.setColorAt(0.0, QColor(0, 206, 209, 100));
    gradient.setColorAt(1.0, QColor(0, 255, 255, 100));
//    gradient.setColorAt(0.0, QColor(35, 182, 230, 100));
//    gradient.setColorAt(1.0, QColor(2, 211, 154, 100));
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    areaSeries->setBrush(gradient);
    areaSeries->setBorderColor(QColor(0, 230, 230, 100));

    QPen pen_RMS(Qt::white); //white
    pen_RMS.setWidth(3);
    series_RMS->setPen(pen_RMS);

    error_plus = new QBarSet("误差(正)");
    error_plus->setColor(QColor(200, 20, 20, 100));
    error_plus->setBorderColor(QColor(200, 20, 20, 255));
    error_minus = new QBarSet("误差(负)");
    error_minus->setColor(QColor(20, 200, 20, 100));
    error_minus->setBorderColor(QColor(20, 200, 20, 255));
    series = new QStackedBarSeries();
    series->append(error_plus);
    series->append(error_minus);
    series->setBarWidth(0.5);

    QPen pen_series_set(QColor(0, 230, 230, 100));
    pen_series_set.setWidth(3);
    series_set->setPen(pen_series_set);

//    QLinearGradient lineGradient;
//    lineGradient.setStart(QPointF(0, 0));
//    lineGradient.setFinalStop(QPointF(1, 0));
//    lineGradient.setColorAt(0.0, QColor(35, 182, 230, 255));
//    lineGradient.setColorAt(1.0, QColor(2, 211, 154, 255));
//    lineGradient.setCoordinateMode(QGradient::StretchToDeviceMode);
//    series_actual->setPen(QPen(QBrush(lineGradient), 3));

    QPen pen_series_actual(QColor(0, 230, 230, 255));
    pen_series_actual.setWidth(3);
    series_actual->setPen(pen_series_actual);

    QFont font1("Times New Roman", 16);
    font1.setBold(true);
    chart->setTitleFont(font1);
    QFont font("宋体", 12);
    font1.setBold(true);
    chart->legend()->setFont(font);
    font.setPointSize(9);
    font.setBold(true);
    m_axisY_red->setLabelsFont(font);
    m_axisY_blue->setLabelsFont(font);
    m_axisY_white->setLabelsFont(font);
    m_axisY_green->setLabelsFont(font);

//    初始化
    for (int i = 0 ; i < len + 1; i++) {
        dataList.append(0);
    }
    for (int i = 0; i < dataList.length(); i++) {
        series_RMS->append(i, dataList.at(i));
        scatter_RMS->append(i, dataList.at(i));
        series_set->append(i, dataList.at(i) + 1);
        series_actual->append(i, dataList.at(i) - 1);
        if (dataList[i] >= 0) {
            error_plus->append(dataList[i]);
            error_minus->append(0);
        } else {
            error_minus->append(dataList[i]);
            error_plus->append(0);
        }
        series->append(error_plus);
        series->append(error_minus);
    }

    chart->addSeries(series);
    chart->addSeries(series_RMS);
    chart->addSeries(scatter_RMS);
    chart->addSeries(series_set);
    chart->addSeries(series_actual);
    chart->addSeries(areaSeries);

    chart->addAxis(m_axisX, Qt::AlignBottom);
    chart->addAxis(m_axisY_red, Qt::AlignLeft);
    chart->addAxis(m_axisY_blue, Qt::AlignRight);
    chart->addAxis(m_axisY_white, Qt::AlignRight);
    chart->addAxis(m_axisY_green, Qt::AlignLeft);

    series->attachAxis(m_axisX);
    series->attachAxis(m_axisY_red);
    series_RMS->attachAxis(m_axisX);
    series_RMS->attachAxis(m_axisY_white);
    scatter_RMS->attachAxis(m_axisX);
    scatter_RMS->attachAxis(m_axisY_white);
    series_set->attachAxis(m_axisX);
    series_set->attachAxis(m_axisY_blue);
    series_actual->attachAxis(m_axisX);
    series_actual->attachAxis(m_axisY_blue);
    areaSeries->attachAxis(m_axisX);
    areaSeries->attachAxis(m_axisY_blue);


    m_axisX->setRange(0, 22);
    m_axisY_red->setRange(-5, 10);
    m_axisY_green->setRange(-5, 10);
    m_axisY_blue->setRange(-10, 20);
    m_axisY_white->setRange(-5, 10);
    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    chart->legend()->markers(scatter_RMS)[0]->setVisible(false);

    connect(scatter_RMS, &QSplineSeries::hovered, this, &MainWindow::tooltip);
    connect(scatter_RMS, &QSplineSeries::clicked, this, &MainWindow::keepCallout);
    this->setMouseTracking(true);

//    connect(m_series, &QXYSeries::clicked, this, &MainWindow::legendMarkerClicked);
//    connect(m_series, &QXYSeries::clicked, this, [&]() {
//        if(m_series->isVisible()) {
//            m_series->setOpacity(0);
//        }
//    });
//    connect(m_series, &QXYSeries::opacityChanged, this, [&]() {
//        if(m_series->opacity() == ) {
//            m_series->setOpacity(0);
//        }
//    });

    foreach (QLegendMarker* marker, chart->legend()->markers()) {
        marker->setShape(QLegend::MarkerShapeCircle);
        QObject::disconnect(marker, SIGNAL(clicked()), this, SLOT(legendMarkerClicked()));
        QObject::connect(marker, SIGNAL(clicked()), this, SLOT(legendMarkerClicked()));
    }

}

void MainWindow::on_pushButton_clicked() {

    if (m_timer.isActive()) {
        m_timer.stop();
        ui->pushButton->setText("go on");
    }

    else {
        m_timer.start();
        ui->pushButton->setText("stop");
        for(int i = 0; i < m_callouts.count() ; i++) {
            m_callouts.at(i)->hide();
        }
        chart->update();
        qDeleteAll(m_callouts);
        m_callouts.clear();
    }
}

void MainWindow::keepCallout() {
    m_callouts.append(m_tooltip);
    m_tooltip = new Callout(chart);
    m_tooltip->hide();
}

void MainWindow::tooltip(QPointF point, bool state) {
    if (m_tooltip == 0) {
        m_tooltip = new Callout(chart);
    }

    if (state) {
        m_tooltip->setText(QString("  %2  ").arg(point.y()));
        m_tooltip->setAnchor(point);
        m_tooltip->setZValue(11);
        m_tooltip->updateGeometry();
        m_tooltip->show();
    } else {
        m_tooltip->hide();
    }
}



void MainWindow::handleTimeout() {
    dataList.removeFirst();

    dataList.append(QRandomGenerator::global()->bounded(15) - 5);
    for (int i = 0; i < len + 1; i++) {
        series_RMS->replace(i, i, dataList.at(i));
        scatter_RMS->replace(i, i, dataList.at(i));

        series_set->replace(i, i, dataList.at(i) + 1);
        series_actual->replace(i, i, dataList.at(i) - 1);
        if (dataList.at(i) - 1 >= 0) {
            error_plus->replace(i, dataList.at(i) - 1);
            error_minus->replace(i, 0);
        } else {
            error_minus->replace(i, dataList.at(i) - 1);
            error_plus->replace(i, 0);
        }
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    chart = new QChart();
    initGraphic();
    LabSocketState = new QLabel("Socket状态："); //
    LabSocketState->setMinimumWidth(200);
    ui->statusBar->addWidget(LabSocketState);

//    QLinearGradient linearGradient(QPointF(0, -200), QPointF(0, 200));
//    linearGradient.setColorAt(0, Qt::red);
//    linearGradient.setColorAt(1, Qt::blue);
//    QBrush brush(linearGradient);

//    auto role = QPalette::Text;
//    ui->label->setText()
//    ui->label->setBrush(role, QBrush(linearGradient));



    QString localIP = getLocalIP(); //本机IP
    this->setWindowTitle(this->windowTitle() + "----本机IP：" + localIP);
    ui->comboTargetIP->addItem(localIP);

    udpSocket = new QUdpSocket(this); //用于与连接的客户端通讯的QTcpSocket

    connect(udpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    onSocketStateChange(udpSocket->state());

    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(onSocketReadyRead()));
}

MainWindow::~MainWindow() {
    udpSocket->abort();
    delete udpSocket;
    delete ui;
}



QString MainWindow::getLocalIP() {
    QString hostName = QHostInfo::localHostName(); //本地主机名
    QHostInfo   hostInfo = QHostInfo::fromName(hostName);
    QString   localIP = "";

    QList<QHostAddress> addList = hostInfo.addresses(); //

    if (!addList.isEmpty())
        for (int i = 0; i < addList.count(); i++) {
            QHostAddress aHost = addList.at(i);
            if (QAbstractSocket::IPv4Protocol == aHost.protocol()) {
                localIP = aHost.toString();
                break;
            }
        }
    return localIP;
}

void MainWindow::legendMarkerClicked() {

    for(int i = 0; i < m_callouts.count() ; i++) {
        m_callouts.at(i)->hide();
    }
    chart->update();
    qDeleteAll(m_callouts);
    m_callouts.clear();

    QLegendMarker* marker = qobject_cast<QLegendMarker*> (sender());
    if (marker == chart->legend()->markers(series_RMS)[0]) {
        if (!scatter_RMS->isVisible()) {
            scatter_RMS->setVisible(true);
            chart->legend()->markers(scatter_RMS)[0]->setVisible(false);
        } else
            scatter_RMS->setVisible(false);
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




void MainWindow::onSocketStateChange(QAbstractSocket::SocketState socketState) {
    switch(socketState) {
    case QAbstractSocket::UnconnectedState:
        LabSocketState->setText("scoket状态：UnconnectedState");
        break;
    case QAbstractSocket::HostLookupState:
        LabSocketState->setText("scoket状态：HostLookupState");
        break;
    case QAbstractSocket::ConnectingState:
        LabSocketState->setText("scoket状态：ConnectingState");
        break;

    case QAbstractSocket::ConnectedState:
        LabSocketState->setText("scoket状态：ConnectedState");
        break;

    case QAbstractSocket::BoundState:
        LabSocketState->setText("scoket状态：BoundState");
        break;

    case QAbstractSocket::ClosingState:
        LabSocketState->setText("scoket状态：ClosingState");
        break;

    case QAbstractSocket::ListeningState:
        LabSocketState->setText("scoket状态：ListeningState");
    }
}

void MainWindow::onSocketReadyRead() {
    //读取收到的数据报
    while(udpSocket->hasPendingDatagrams()) {
        QByteArray   datagram;
        datagram.resize(udpSocket->pendingDatagramSize());

        QHostAddress    peerAddr;
        quint16 peerPort;
        udpSocket->readDatagram(datagram.data(), datagram.size(), &peerAddr, &peerPort);
        QString str = datagram.data();

        QString peer = "[From1 " + peerAddr.toString() + ":" + QString::number(peerPort) + "] ";

        ui->plainTextEdit->appendPlainText(peer + str);
    }
}

void MainWindow::on_actStart_triggered() {
    //绑定端口
    quint16     port = ui->spinBindPort->value(); //本机UDP端口
    if (udpSocket->bind(port)) { //绑定端口成功
        ui->plainTextEdit->appendPlainText("**已成功绑定");
        ui->plainTextEdit->appendPlainText("**绑定端口："
                                           + QString::number(udpSocket->localPort()));

        ui->actStart->setEnabled(false);
        ui->actStop->setEnabled(true);
    } else
        ui->plainTextEdit->appendPlainText("**绑定失败");
}

void MainWindow::on_actStop_triggered() {
    //解除绑定
    udpSocket->abort(); //不能解除绑定
    ui->actStart->setEnabled(true);
    ui->actStop->setEnabled(false);
    ui->plainTextEdit->appendPlainText("**已解除绑定");
}

void MainWindow::on_actClear_triggered() {
    ui->plainTextEdit->clear();
}

void MainWindow::on_btnSend_clicked() {
    //发送消息 按钮
    QString     targetIP = ui->comboTargetIP->currentText(); //目标IP
    QHostAddress    targetAddr(targetIP);

    quint16     targetPort = ui->spinTargetPort->value(); //目标port

    QString  msg = ui->editMsg->text(); //发送的消息内容

    QByteArray  str = msg.toUtf8();
    udpSocket->writeDatagram(str, targetAddr, targetPort); //发出数据报

    ui->plainTextEdit->appendPlainText("[out] " + msg);
    ui->editMsg->clear();
    ui->editMsg->setFocus();
}

void MainWindow::on_actHostInfo_triggered() {
    //本机地址 按钮
    QString hostName = QHostInfo::localHostName(); //本地主机名
    ui->plainTextEdit->appendPlainText("本机主机名：" + hostName + "\n");
    QHostInfo   hostInfo = QHostInfo::fromName(hostName);

    QList<QHostAddress> addList = hostInfo.addresses(); //
    if (!addList.isEmpty())
        for (int i = 0; i < addList.count(); i++) {
            QHostAddress aHost = addList.at(i);
            if (QAbstractSocket::IPv4Protocol == aHost.protocol()) {
                QString IP = aHost.toString();
                ui->plainTextEdit->appendPlainText("本机IP地址：" + aHost.toString());
                if (ui->comboTargetIP->findText(IP) < 0)
                    ui->comboTargetIP->addItem(IP);
            }
        }

}

void MainWindow::on_btnBroadcast_clicked() {
    //广播消息 按钮
    quint16     targetPort = ui->spinTargetPort->value(); //目标端口
    QString  msg = ui->editMsg->text();
    QByteArray  str = msg.toUtf8();
    udpSocket->writeDatagram(str, QHostAddress::Broadcast, targetPort);

    ui->plainTextEdit->appendPlainText("[broadcast] " + msg);
    ui->editMsg->clear();
    ui->editMsg->setFocus();
}


