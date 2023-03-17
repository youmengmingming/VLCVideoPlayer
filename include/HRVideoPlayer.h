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
    /*���ļ���ť�Ĳۺ���*/
    void on_pushButton_open_clicked();

    /*������ͣ��ť�Ĳۺ���*/
    void on_pushButton_play_clicked();

    /*ֹͣ���Ű�ť�Ĳۺ���*/
    void on_pushButton_stop_clicked();

    /*ȫ�����Ű�ť�Ĳۺ���*/
    void on_pushButton_fullScreen_clicked();

    /*�ٶȱ仯�Ĳۺ���*/
    void setSpeed(double speed);

    /*�������ƶ��Ĳۺ���*/
    void slotSliderMoved(int val);

    /*��ʱ���Ĳۺ���*/
    void slotTimeOut();

private:
    Ui::HRVideoPlayerClass *ui;
    VlcPlayer* _vlcPlayer;
    int _currentTime;
    int _totalTime;
    QTimer* totalTimer;
};
