#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<Thread_mp4_pic.h>
#include<QProcess>
#include<QTimer>
#include <QNetworkAccessManager>
#include<QNetworkReply>

#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>

static int time_num=0;
static int advert =0;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showFont();

public slots:
    void pic_show(QString);//图片显示
    void mp4Play();//视频播放

    void showtime();

    void showWeather(QNetworkReply *reply);
    void play_auto();//进程结束槽函数

    void play_mp4();
private:
    Ui::MainWindow *ui;
    Thread_mp4_pic * thread_pic_mp4;
    QProcess mp4_process;
    QTimer * timer;

    QTimer * mp4_timer;
    QStringList mp4_name;
    int mp4_num;


    QStringList list_advert;
    QNetworkAccessManager * manager;


};
#endif // MAINWINDOW_H
