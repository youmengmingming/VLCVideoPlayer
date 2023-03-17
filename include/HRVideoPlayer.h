#pragma once

#include <QWidget>
#include<QTimer>
#include<QKeyEvent>

#include "ui_HRVideoPlayer.h"
#include"VlcPlayer.h"

class HRVideoPlayer : public QWidget
{
    Q_OBJECT

public:
    HRVideoPlayer(QWidget *parent = nullptr);
    ~HRVideoPlayer();

    static QString formatTime(int p_iMilliSeconds);

    void keyPressEvent(QKeyEvent* event);


public slots:
    /*打开文件按钮的槽函数*/
    void on_pushButton_open_clicked();

    /*播放暂停按钮的槽函数*/
    void on_pushButton_play_clicked();

    /*停止播放按钮的槽函数*/
    void on_pushButton_stop_clicked();

    /*全屏播放按钮的槽函数*/
    void on_pushButton_fullScreen_clicked();

    /*速度变化的槽函数*/
    void setSpeed(double speed);

    /*滑动条移动的槽函数*/
    void slotSliderMoved(int val);

    /*计时器的槽函数*/
    void slotTimeOut();

private:
    Ui::HRVideoPlayerClass *ui;
    VlcPlayer* _vlcPlayer;
    int _currentTime;
    int _totalTime;
    QTimer* totalTimer;
};
