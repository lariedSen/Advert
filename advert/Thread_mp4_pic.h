#ifndef THREAD_MP4_PIC_H
#define THREAD_MP4_PIC_H
#include<QThread>
#include<QDebug>
#include<QDateTime>
#include<QDir>
class Thread_mp4_pic: public QThread
{
    Q_OBJECT
public:
    Thread_mp4_pic(QWidget*parent = nullptr)
    {

    }


signals:
    void show(QString );
    void mp4_show();
public:
    void run() override
    {
         int i ;
#ifdef Q_OS_WIN32

        QDir dir("../advert/pic", "Images (*.png  *.jpg)");
 #endif

 #ifdef Q_OS_LINUX

        QDir dir("./jpg", "*.jpg");
  #endif
        dir.setFilter(QDir::Dirs|QDir::Files);//除了目录或文件，其他的过滤掉
        QFileInfoList list = dir.entryInfoList();


        while (1)
        {
           //照片
            for(i =0;i<list.count();i++)
            {
                if(list.at(i).fileName() =="."|list.at(i).fileName()=="..")
                {
                    qDebug()<<"."<<"or"<<"..";
                    continue;
                }
                filepath = list.at(i).filePath();
                qDebug()<<filepath;
                emit show(filepath);
                QThread::sleep(2);
            }

            if(i == list.count())
            {
                filepath.clear();
                emit show(filepath);
                QThread::sleep(2);
            }
            emit mp4_show();
            break;
        }
    }

private:
    QString filepath;
};


#endif // THREAD_MP4_PIC_H
