#ifndef UDPTHREAD_H
#define UDPTHREAD_H

#include <QObject>
#include <QtNetwork\QUdpSocket>
#include <QTimer>
#include <QList>
#include <QtMath>
#include <QThread>

class udpThread : public QObject {
    Q_OBJECT

  private:
    double CurrAZ, CurrH; // 实际秒
    QList<double> CErrAZList, CErrHList;
  public:
    static int count, counti;
    static double sumH2, sumAZ2;
    static int speed_H, speed_AZ;
    static bool AZEnable, HEnable, draw_flag;
    static bool AZForLmt, AZRevLmt, HForLmt, HRevLmt;
    static bool AZSoftForLmt, AZSoftRevLmt, HSoftForLmt, HSoftRevLmt;
    static int CurrAZCount, CurrHCount; // 实际位置 count
    static double TargetAZ, TargetH;   // 理论位置 / 角秒
    static double ErrAZ, ErrH, RMSH, RMSAZ;
    static QList<int> TargetAZList, TargetHList;
    static QList<double> ErrAZList, ErrHList, RMSAZList, RMSHList, CurrHList, CurrAZList;
    static int datatime, datatimems;
    static bool Sendready;
    void listClear();
    explicit udpThread(QObject *parent = 0);
    QUdpSocket *udpsocket;

  signals:
    void dataready();
    void graphDataReady();
  private slots:

  protected:

  public slots:
    void run();
    void readfun();
    void writefun(QByteArray ba);
    void closeudp();

};

#endif // UDPTHREAD_H
