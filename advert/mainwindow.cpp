#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QDateTime>
#include<QDebug>
#include<QUrl>
#include<QSplitter>
#include<QMessageBox>
/*************************************************
Copyright:
Author:Laried
Date:2020年7月22日
Description (描述主要实现的功能):
    1.实现广告界面的图片轮、视频轮播
    2.实时获取日期和天气信心：QJson
    3.在linux和win32系统的皆可运行

Diffculties:
    1.图片和视频切换期间不能无缝切换，有明显时间空隙
    2.视频于视频的轮播不能无缝切换，有明显时间空隙
    3.艺术设计：老是这么丑的界面设计
**************************************************/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mp4_num =0;

    this->resize(800,480);
    //线程：照片和视频播放
    thread_pic_mp4= new Thread_mp4_pic(this);
    connect(thread_pic_mp4,&Thread_mp4_pic::show,this,&MainWindow::pic_show);
    connect(thread_pic_mp4,&Thread_mp4_pic::mp4_show,this,&MainWindow::mp4Play);
    thread_pic_mp4->start();

    //图片播放完毕，开始播放视频
    mp4_timer = new QTimer();
    connect(mp4_timer,&QTimer::timeout,this, &MainWindow::play_mp4);
    //视频播放完成，发射finished()信号，
    connect(&mp4_process,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(play_auto()));



    //计时
    timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&MainWindow::showtime);
    timer->start(1000);

    //词条滚动
    list_advert<<"美肤说，为你的美说--艾霏莱婷，您私人的护肤专家"
              <<"精致容颜美丽说——美肤说"<<"每时每刻，美肤说/每分每秒，你值得拥有"
             <<"锁住你年龄的秘密，定格你最红的年纪——艾霏莱婷，"
            <<"有你的日子，每一天都很美";
    ui->label_font->setText("艾菲·莱婷——让您做完美的丽质女人");

    //天气Json，发起请求
    manager = new QNetworkAccessManager();
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::showWeather);
    QUrl url("http://apis.juhe.cn/simpleWeather/query?"
             "city=%E5%B9%BF%E5%B7%9E&key=813b9882ce5bc87170516a3d7e11026b");
    manager->get(QNetworkRequest(url));


}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief  图片轮播
 *
 * @param
 * @return
**/
void MainWindow::pic_show(QString pic_name)
{
    if(pic_name.isEmpty())
    {
        ui->label_mp4->clear();
        ui->label_mp4->setText(QString("其实变美很简单\n "
                                       "透白雪肤，美白奇迹：\n "
                                        "欢迎致电联系：%1 \n")
                                       .arg("1314****536"));
        ui->label_mp4->setStyleSheet("background-color: rgb(220, 254, 255);");
    }

    QPixmap pixmap(pic_name);
    pixmap = pixmap.scaled(ui->label_mp4->size(),Qt::IgnoreAspectRatio);
    ui->label_mp4->setPixmap(pixmap);
}



/**
 * @brief  播放完成，
 *
 * @param
 * @return
**/
void MainWindow::play_auto()
{
    if(mp4_process.state() == QProcess::NotRunning)
    {

        ui->label_mp4->setText(QString("其实变美很简单\n "
                                       "透白雪肤，美白奇迹：\n "
                                        "欢迎致电联系：%1 \n")
                                       .arg("1314****536"));
        ui->label_mp4->setStyleSheet("background-color: rgb(220, 254, 255);");

        if(mp4_num == mp4_name.count())
        {
            qDebug()<<"&&&&&&&&&&&&&&&&&&&&&&";
            thread_pic_mp4->start();
        }
        else
        {
            mp4_timer->start(2000);
        }


    }



}


/**
 * @brief 开始播放视频
 *
 * @param
 * @return
**/
void MainWindow::play_mp4()
{
    mp4_timer->stop();



    //win系统
    #ifdef Q_OS_WIN32
        QStringList argments ;
        argments<<"-slave"<<"-quiet"<<"-zoom"<<"-wid"
               <<QString::number(ui->label_mp4->winId())<<mp4_name[mp4_num];
        mp4_process.start("C:/mplayer/mplayer.exe",argments);

        if(mp4_process.state() == QProcess::Running)
        {
            qDebug()<<"8************"<<"runing";
        }
     #endif

    //linux 系统

    #ifdef Q_OS_LINUX

        QString cmd = QString("mplayer -slave -quiet "
                              "-geometry %1:%2 -zoom -x %3 -y %4 "
                              "%5")
                            .arg(ui->label_mp4->x())
                            .arg(ui->label_mp4->y())
                                .arg(ui->label_mp4->width())
                                .arg(ui->label_mp4->height())
                                .arg(mp4_name[mp4_num]) ;

        qDebug() << "cmd = " << cmd;
        mp4_process.start(cmd);
        if(mp4_process.state() == QProcess::Running)
        {
            qDebug()<<"8************"<<"runing";
        }


    #endif

   mp4_num++;
}


/**
 * @brief  播放视频
 *
 * @param
 * @return
**/
void MainWindow::mp4Play()
{
     this->mp4_name.clear();
     mp4_num =0;




//1. win系统 和 linux 系统   的路径获取
#ifdef Q_OS_WIN32
    QDir dir("../advert/mp4","*.mp4");
#endif
#ifdef Q_OS_LINUX
    QDir dir("./mp4","*.mp4");
#endif


//2. 获取文件名
    dir.setFilter(QDir::Dirs|QDir::Files);//除了目录或文件，其他的过滤掉
    QFileInfoList list = dir.entryInfoList();
    for(int i =0;i<list.count();i++)
    {
//        if(list.at(i).fileName() =="."|list.at(i).fileName()=="..")
//        {
//            qDebug()<<"."<<"or"<<"..";
//            continue;
//        }
        qDebug()<<list.at(i).filePath();
       this->mp4_name<<list.at(i).filePath();
    }

//3. 退出进程
    if(mp4_process.state()==QProcess::Running)
    {
        mp4_process.kill();
        mp4_process.waitForFinished();


    }
    //4. 开启定时器：准备播放视频
    if(mp4_process.state()==QProcess::NotRunning)
    mp4_timer->start(1000);

}



/**
 * @brief  词条滚动
 *
 * @param
 * @return
**/
void MainWindow::showFont()
{
    ui->label_font->setText(list_advert.at(advert++));
    if(advert==list_advert.size())
    {
        advert=0;
    }
}


/**
 * @brief  显示时间+词条
 *
 * @param
 * @return
**/
void MainWindow::showtime()
{
    QDateTime datatime;
    ui->label_time->setText(QString("%1")
                                .arg(datatime.currentDateTime().time().toString("hh:mm:ss")));
    if(++time_num == 5)
    {
        showFont();
        time_num=0;
    }
}



/**
 * @brief  QJson 天气等显示
 *
 * @param
 * @return
**/
void MainWindow::showWeather(QNetworkReply *reply)
{

    qDebug()<<"========================";
    //1.获取Json数据
    QByteArray array_read= reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(array_read);
    QJsonObject obj = doc.object();
    QJsonObject obj_result = obj.value("result").toObject();
    QString city = obj_result.value("city").toString();
    QJsonArray future_array = obj_result.value("future").toArray();
    QJsonObject obj_today=  future_array.at(0).toObject();
    QString date_y =  obj_today.value("date").toString();
    QString temperature= obj_today.value("temperature").toString();
    QString weather= obj_today.value("weather").toString();
    QString dressing_index= obj_today.value("direct").toString();

    ui->label_date->setText(date_y);
    ui->label_local->setText(city);
    ui->label_weather->setText(weather);
    ui->label_temperature->setText(temperature);
    ui->label_dressing_index->setText(dressing_index);

    //2.设置天气图标
    QPixmap pixmap;
    if(weather.contains(("晴"),Qt::CaseInsensitive))
    {
        pixmap.load(":/sun.png");
        ui->label_icon->setPixmap(
                    pixmap.scaled(ui->label_icon->size(),Qt::KeepAspectRatio));
    }
    else if(weather.contains(("雨"),Qt::CaseInsensitive))
    {
        pixmap.load(":/rain.png");
        ui->label_icon->setPixmap(
                    pixmap.scaled(ui->label_icon->size(),Qt::KeepAspectRatio));
    }
    else if(weather.contains(("云"),Qt::CaseInsensitive)){
        pixmap.load(":/could.png");
        ui->label_icon->setPixmap(
                    pixmap.scaled(ui->label_icon->size(),Qt::KeepAspectRatio));
    }
    else{}
}



