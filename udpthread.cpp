#include "udpthread.h"
#include <QDebug>
#include <QtNetwork>
#include <QThread>
#include <windows.h>

static int POINT_NUM = 51;
static int RMS_NUM = 100;

int udpThread::count = 1;
double udpThread::sumH2 = 0;
double udpThread::sumAZ2 = 0;
bool udpThread::draw_flag = true;
int udpThread::counti = 0;
bool udpThread::AZEnable = 0;
bool udpThread::HEnable = 0;

int udpThread::CurrAZCount = 0; // 实际位置 count
int udpThread::CurrHCount = 0;
double udpThread::TargetAZ = 0; // 理论位置 / 角秒
double udpThread::TargetH = 0;
int udpThread::speed_H = 0;
int udpThread::speed_AZ = 0;
double udpThread::ErrAZ = 0;
double udpThread::ErrH = 0;
double udpThread::RMSH = 0;
double udpThread::RMSAZ = 0;
int udpThread::datatime = 0;
int udpThread::datatimems = 0;

QList<double> udpThread::ErrAZList = QList<double>();
QList<double> udpThread::ErrHList = QList<double>();
QList<int> udpThread::TargetAZList = QList<int>();
QList<int> udpThread::TargetHList = QList<int>();
QList<double> udpThread::CurrAZList = QList<double>();
QList<double> udpThread::CurrHList = QList<double>();
QList<double> udpThread::RMSHList = QList<double>();
QList<double> udpThread::RMSAZList = QList<double>();



void udpThread::listClear() {
    CErrHList.clear();
    sumH2 = 0;
    CErrAZList.clear();
    sumAZ2 = 0;

    ErrAZList.clear();
    ErrHList.clear();
    RMSHList.clear();
    RMSAZList.clear();
    TargetHList.clear();
    TargetAZList.clear();
    CurrHList.clear();
    CurrAZList.clear();
    while( CErrAZList.size() < POINT_NUM ) CErrAZList.append(0.0);
    while( CErrHList.size() < POINT_NUM ) CErrHList.append(0.0);
    while( udpThread::ErrAZList.size() < POINT_NUM ) udpThread::ErrAZList.append(0.0);
    while( udpThread::ErrHList.size() < POINT_NUM ) udpThread::ErrHList.append(0);
    while( udpThread::RMSHList.size() < POINT_NUM ) udpThread::RMSHList.append(0.0);
    while( udpThread::RMSAZList.size() < POINT_NUM ) udpThread::RMSAZList.append(0.0);
    while( udpThread::TargetHList.size() < POINT_NUM ) udpThread::TargetHList.append(0);
    while( udpThread::TargetAZList.size() < POINT_NUM ) udpThread::TargetAZList.append(0);
    while( udpThread::CurrHList.size() < POINT_NUM ) udpThread::CurrHList.append(0);
    while( udpThread::CurrAZList.size() < POINT_NUM ) udpThread::CurrAZList.append(0);

}

udpThread::udpThread(QObject *parent) : QObject(parent) {
    listClear();
}

void udpThread::run() {

    udpsocket = new QUdpSocket();

    if (udpsocket->bind(QHostAddress("192.168.3.126"), 2019)) // 192.168.3.14 : 2020
//    if (udpsocket->bind(QHostAddress("127.0.0.1"), 2019))
        qDebug() << " bind 成功 " + QString::number(udpsocket->localPort());
    else
        qDebug() << " bind 失败 ";
    //    qDebug() << "udpthread run:" << QThread::currentThread();
    connect(udpsocket, &QUdpSocket::readyRead, this, &udpThread::readfun,
            Qt::DirectConnection);
}
void udpThread::writefun(QByteArray ba) {
    udpsocket->writeDatagram(ba, QHostAddress("192.168.3.14"), 2020);
//    udpsocket->writeDatagram(ba, QHostAddress("127.0.0.1"), 2020);
//    qDebug() << "udpthread write:" << QThread::currentThread() << "DATA" << QString(ba.toHex(' '));
}


void udpThread::readfun() {

    while (udpsocket->hasPendingDatagrams()) {
        counti++;
        QByteArray data;
        data.resize(udpsocket->pendingDatagramSize());
        udpsocket->readDatagram(data.data(), data.size());
//        qDebug() << data.size() ;
        if (data.size() <= 0)
            return;

        char *udpdata = data.data();
        char AZState, HState;
        if (udpdata[0] == 'S' && data.size() == 53 && udpdata[52] == 'W') {
            qDebug() << "udpthread read:" << QString(data.toHex(' '));

            AZState = udpdata[2];
            HState = udpdata[3];
            AZEnable = (int(AZState & 0x01) == 1 ? 1 : 0);
            HEnable = (int(HState & 0x01) == 1 ? 1 : 0);

            int iTargetAZ, iTargetH, iErrAZ, iErrH;
            memcpy(&CurrAZCount, udpdata + 6, 4); // 实际位置
            memcpy(&CurrHCount, udpdata + 10, 4);
            CurrHCount = BLEndianUint32(CurrHCount);
            CurrAZCount = BLEndianUint32(CurrAZCount);
            CurrH = CurrHCount / 10.0;
            CurrAZ = CurrAZCount / 10.0;

            memcpy(&iTargetAZ, udpdata + 14, 4); // 理论位置
            memcpy(&iTargetH, udpdata + 18, 4);
            iTargetAZ = BLEndianUint32(iTargetAZ);
            iTargetH = BLEndianUint32(iTargetH);
            TargetAZ = iTargetAZ / 10.0;
            TargetH = iTargetH / 10.0;

            memcpy(&iErrAZ, udpdata + 22, 4); // 误差
            memcpy(&iErrH, udpdata + 26, 4);
            iErrH = BLEndianUint32(iErrH);
            iErrAZ = BLEndianUint32(iErrAZ);
            ErrAZ = iErrAZ / 10.0;
            ErrH = iErrH / 10.0;

            CErrAZList << ErrAZ;
            sumAZ2 += ErrAZ * ErrAZ;
            if (CErrAZList.size() > RMS_NUM) {
                sumAZ2 -= CErrAZList[0] * CErrAZList[0];
                CErrAZList.removeFirst();
            }

            CErrHList << ErrH;
            sumH2 += ErrH * ErrH;
            if (CErrHList.size() > 100) {
                sumH2 -= CErrHList[0] * CErrHList[0];
                CErrHList.removeFirst();
            }

            memcpy(&speed_AZ, udpdata + 30, 4); // 速度
            memcpy(&speed_H, udpdata + 34, 4);
            speed_AZ = BLEndianUint32(speed_AZ);
            speed_H = BLEndianUint32(speed_H);

//            if (sumH2 < 0 ) RMSH = 0;
//            else
            RMSH = qSqrt(sumH2 / CErrHList.size());

//            if (RMSAZ < 0 ) RMSAZ = 0;
//            else
            RMSAZ = qSqrt(sumAZ2 / CErrAZList.size());


            memcpy(&datatime, udpdata + 39, 4);
            memcpy(&datatimems, udpdata + 43, 2);
            datatime = BLEndianUint32(datatime);

            if ( draw_flag && counti >= count ) {
                counti = 0;

                CurrAZList << CurrAZ;
                TargetAZList << TargetAZ;
                if (CurrAZList.size() > POINT_NUM) {
                    CurrAZList.removeFirst();
                    TargetAZList.removeFirst();
                }
                CurrHList << CurrH;
                TargetHList << TargetH;
                if (CurrHList.size() > POINT_NUM) {
                    CurrHList.removeFirst();
                    TargetHList.removeFirst();
                }

                ErrHList << ErrH;
                if (ErrHList.size() > POINT_NUM) {
                    ErrHList.removeFirst();
                }
                ErrAZList << ErrAZ;
                if (ErrAZList.size() > POINT_NUM) {
                    ErrAZList.removeFirst();
                }

                RMSHList << RMSH;
                if (RMSHList.size() > POINT_NUM)
                    RMSHList.removeFirst();
                RMSAZList << RMSAZ;
                if (RMSAZList.size() > POINT_NUM)
                    RMSAZList.removeFirst();

                emit graphDataReady();
            }

            emit dataready();
        }
    }
}

void udpThread::closeudp() {
    udpsocket->close();
    delete udpsocket;
    qDebug() << "udpthread close:" << QThread::currentThread();
}

