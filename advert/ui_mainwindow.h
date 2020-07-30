/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_date;
    QLabel *label_temperature;
    QLabel *label_weather;
    QLabel *label_icon;
    QLabel *label_dressing_index;
    QLabel *label_time;
    QLabel *label_local;
    QLabel *label_mp4;
    QLabel *label_font;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setMaximumSize(QSize(1000, 1000));
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_date = new QLabel(centralwidget);
        label_date->setObjectName(QStringLiteral("label_date"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_date->sizePolicy().hasHeightForWidth());
        label_date->setSizePolicy(sizePolicy);
        label_date->setMinimumSize(QSize(0, 0));
        label_date->setMaximumSize(QSize(400, 16777215));
        QFont font;
        font.setPointSize(15);
        label_date->setFont(font);
        label_date->setStyleSheet(QStringLiteral(""));
        label_date->setFrameShape(QFrame::NoFrame);
        label_date->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(label_date, 0, 0, 1, 2);

        label_temperature = new QLabel(centralwidget);
        label_temperature->setObjectName(QStringLiteral("label_temperature"));
        sizePolicy.setHeightForWidth(label_temperature->sizePolicy().hasHeightForWidth());
        label_temperature->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(14);
        label_temperature->setFont(font1);
        label_temperature->setStyleSheet(QStringLiteral(""));
        label_temperature->setFrameShape(QFrame::NoFrame);
        label_temperature->setFrameShadow(QFrame::Sunken);
        label_temperature->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_temperature, 3, 0, 1, 2);

        label_weather = new QLabel(centralwidget);
        label_weather->setObjectName(QStringLiteral("label_weather"));
        sizePolicy.setHeightForWidth(label_weather->sizePolicy().hasHeightForWidth());
        label_weather->setSizePolicy(sizePolicy);
        label_weather->setFont(font1);
        label_weather->setStyleSheet(QStringLiteral(""));
        label_weather->setFrameShape(QFrame::NoFrame);
        label_weather->setFrameShadow(QFrame::Sunken);
        label_weather->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_weather, 4, 0, 1, 1);

        label_icon = new QLabel(centralwidget);
        label_icon->setObjectName(QStringLiteral("label_icon"));
        sizePolicy.setHeightForWidth(label_icon->sizePolicy().hasHeightForWidth());
        label_icon->setSizePolicy(sizePolicy);
        label_icon->setFont(font1);
        label_icon->setFrameShape(QFrame::NoFrame);
        label_icon->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(label_icon, 4, 1, 1, 1);

        label_dressing_index = new QLabel(centralwidget);
        label_dressing_index->setObjectName(QStringLiteral("label_dressing_index"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_dressing_index->sizePolicy().hasHeightForWidth());
        label_dressing_index->setSizePolicy(sizePolicy1);
        label_dressing_index->setFont(font1);

        gridLayout->addWidget(label_dressing_index, 5, 0, 1, 2);

        label_time = new QLabel(centralwidget);
        label_time->setObjectName(QStringLiteral("label_time"));
        sizePolicy1.setHeightForWidth(label_time->sizePolicy().hasHeightForWidth());
        label_time->setSizePolicy(sizePolicy1);
        label_time->setMinimumSize(QSize(0, 0));
        label_time->setMaximumSize(QSize(400, 16777215));
        label_time->setFont(font);
        label_time->setStyleSheet(QStringLiteral(""));
        label_time->setFrameShape(QFrame::NoFrame);
        label_time->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(label_time, 1, 0, 1, 2);

        label_local = new QLabel(centralwidget);
        label_local->setObjectName(QStringLiteral("label_local"));
        sizePolicy.setHeightForWidth(label_local->sizePolicy().hasHeightForWidth());
        label_local->setSizePolicy(sizePolicy);
        label_local->setFont(font1);
        label_local->setStyleSheet(QStringLiteral(""));
        label_local->setFrameShape(QFrame::NoFrame);
        label_local->setFrameShadow(QFrame::Sunken);
        label_local->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_local, 2, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 2, 1, 1, 1);

        label_mp4 = new QLabel(centralwidget);
        label_mp4->setObjectName(QStringLiteral("label_mp4"));
        label_mp4->setMinimumSize(QSize(620, 400));
        label_mp4->setMaximumSize(QSize(620, 1000));

        gridLayout_2->addWidget(label_mp4, 2, 0, 1, 1);

        label_font = new QLabel(centralwidget);
        label_font->setObjectName(QStringLiteral("label_font"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_font->sizePolicy().hasHeightForWidth());
        label_font->setSizePolicy(sizePolicy2);
        label_font->setMinimumSize(QSize(0, 35));
        label_font->setMaximumSize(QSize(16777215, 40));
        QFont font2;
        font2.setPointSize(20);
        label_font->setFont(font2);
        label_font->setStyleSheet(QStringLiteral("background-color: rgb(243, 255, 244);"));
        label_font->setFrameShape(QFrame::Box);
        label_font->setFrameShadow(QFrame::Sunken);
        label_font->setLineWidth(2);

        gridLayout_2->addWidget(label_font, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_date->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\346\227\245\346\234\237", 0));
        label_temperature->setText(QApplication::translate("MainWindow", "temperature", 0));
        label_weather->setText(QApplication::translate("MainWindow", "weather", 0));
        label_icon->setText(QApplication::translate("MainWindow", "\345\233\276\346\240\207", 0));
        label_dressing_index->setText(QApplication::translate("MainWindow", "dressing_index", 0));
        label_time->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264", 0));
        label_local->setText(QApplication::translate("MainWindow", "\345\271\277\345\267\236", 0));
        label_mp4->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_font->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
