#pragma once

#include <QObject>
#include<qwindowdefs.h>

#include<vlc/vlc.h>
#include<vlc/libvlc.h>
#include<vlc/libvlc_media.h>
#include<vlc/libvlc_media_player.h>

class VlcPlayer  : public QObject
{
	Q_OBJECT

public:
	VlcPlayer(QObject *parent);
	~VlcPlayer();
	/*设置媒体路径包含名字*/
	void setMediaName(QString mediaName);
	/*创建实例、媒体、播放器*/
	void createPlayer();
	/*播放器播放*/
	void playMedia();
	/*播放器暂停*/
	void pauseMedia();
	/*播放器停止*/
	void stopMedia();
	/*获取媒体的长度，单位为ms*/
	int getMediaLength();
	/*设置播放窗口*/
	void setWId(WId id);
	/*设置播放速度*/
	void setSpeed(int speed);
	/*设置跳转时间，单位为ms*/
	void setJumpTime(int time);
	/*判断播放器是否正在播放*/
	bool isPlayerPlaying();
	/*判断播放器是否能播放*/
	/*该接口好像存在点错误*/
	bool isPlayerAble();
	/*判断播放器是否存在*/
	bool isPlayerNull();

private:
	libvlc_instance_t* _pinstance;//实例
	libvlc_media_t* _pmedia;//媒体
	libvlc_media_player_t* _pplayer;//播放器
	QString _mediaPath;//包含路径及名称
	int _mediaLength;//单位ms
	WId _hwnd;//窗口句柄
};
