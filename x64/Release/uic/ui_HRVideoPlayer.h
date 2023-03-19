/********************************************************************************
** Form generated from reading UI file 'HRVideoPlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HRVIDEOPLAYER_H
#define UI_HRVIDEOPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HRVideoPlayerClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_video;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_open;
    QPushButton *pushButton_play;
    QPushButton *pushButton_stop;
    QDoubleSpinBox *doubleSpinBox_speed;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_start;
    QSlider *hSlider;
    QLabel *label_end;
    QPushButton *pushButton_fullScreen;

    void setupUi(QWidget *HRVideoPlayerClass)
    {
        if (HRVideoPlayerClass->objectName().isEmpty())
            HRVideoPlayerClass->setObjectName(QStringLiteral("HRVideoPlayerClass"));
        HRVideoPlayerClass->resize(959, 572);
        gridLayout = new QGridLayout(HRVideoPlayerClass);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        label_video = new QLabel(HRVideoPlayerClass);
        label_video->setObjectName(QStringLiteral("label_video"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_video->sizePolicy().hasHeightForWidth());
        label_video->setSizePolicy(sizePolicy);
        label_video->setAutoFillBackground(false);
        label_video->setStyleSheet(QStringLiteral(""));
        label_video->setFrameShape(QFrame::Box);
        label_video->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(label_video);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_open = new QPushButton(HRVideoPlayerClass);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));
        pushButton_open->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(pushButton_open);

        pushButton_play = new QPushButton(HRVideoPlayerClass);
        pushButton_play->setObjectName(QStringLiteral("pushButton_play"));
        pushButton_play->setMaximumSize(QSize(50, 16777215));
        pushButton_play->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(pushButton_play);

        pushButton_stop = new QPushButton(HRVideoPlayerClass);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setMaximumSize(QSize(50, 16777215));
        pushButton_stop->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(pushButton_stop);

        doubleSpinBox_speed = new QDoubleSpinBox(HRVideoPlayerClass);
        doubleSpinBox_speed->setObjectName(QStringLiteral("doubleSpinBox_speed"));
        doubleSpinBox_speed->setStyleSheet(QStringLiteral(""));
        doubleSpinBox_speed->setMinimum(0.25);
        doubleSpinBox_speed->setMaximum(8);
        doubleSpinBox_speed->setSingleStep(0.25);
        doubleSpinBox_speed->setValue(1);

        horizontalLayout->addWidget(doubleSpinBox_speed);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_start = new QLabel(HRVideoPlayerClass);
        label_start->setObjectName(QStringLiteral("label_start"));
        label_start->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(label_start);

        hSlider = new QSlider(HRVideoPlayerClass);
        hSlider->setObjectName(QStringLiteral("hSlider"));
        hSlider->setStyleSheet(QStringLiteral(""));
        hSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(hSlider);

        label_end = new QLabel(HRVideoPlayerClass);
        label_end->setObjectName(QStringLiteral("label_end"));
        label_end->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(label_end);


        horizontalLayout->addLayout(horizontalLayout_2);

        pushButton_fullScreen = new QPushButton(HRVideoPlayerClass);
        pushButton_fullScreen->setObjectName(QStringLiteral("pushButton_fullScreen"));
        pushButton_fullScreen->setMaximumSize(QSize(50, 16777215));
        pushButton_fullScreen->setAutoFillBackground(false);
        pushButton_fullScreen->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(pushButton_fullScreen);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(HRVideoPlayerClass);

        QMetaObject::connectSlotsByName(HRVideoPlayerClass);
    } // setupUi

    void retranslateUi(QWidget *HRVideoPlayerClass)
    {
        HRVideoPlayerClass->setWindowTitle(QApplication::translate("HRVideoPlayerClass", "Form", Q_NULLPTR));
        label_video->setText(QString());
        pushButton_open->setText(QApplication::translate("HRVideoPlayerClass", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        pushButton_play->setText(QApplication::translate("HRVideoPlayerClass", "\346\222\255\346\224\276", Q_NULLPTR));
        pushButton_stop->setText(QApplication::translate("HRVideoPlayerClass", "\345\201\234\346\255\242", Q_NULLPTR));
        label_start->setText(QApplication::translate("HRVideoPlayerClass", "00\357\274\23200\357\274\23200", Q_NULLPTR));
        label_end->setText(QApplication::translate("HRVideoPlayerClass", "00\357\274\23200\357\274\23200", Q_NULLPTR));
        pushButton_fullScreen->setText(QApplication::translate("HRVideoPlayerClass", "\345\205\250\345\261\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HRVideoPlayerClass: public Ui_HRVideoPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HRVIDEOPLAYER_H
