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
	/*����ý��·����������*/
	void setMediaName(QString mediaName);
	/*����ʵ����ý�塢������*/
	void createPlayer();
	/*����������*/
	void playMedia();
	/*��������ͣ*/
	void pauseMedia();
	/*������ֹͣ*/
	void stopMedia();
	/*��ȡý��ĳ��ȣ���λΪms*/
	int getMediaLength();
	/*���ò��Ŵ���*/
	void setWId(WId id);
	/*���ò����ٶ�*/
	void setSpeed(int speed);
	/*������תʱ�䣬��λΪms*/
	void setJumpTime(int time);
	/*�жϲ������Ƿ����ڲ���*/
	bool isPlayerPlaying();
	/*�жϲ������Ƿ��ܲ���*/
	/*�ýӿں�����ڵ����*/
	bool isPlayerAble();
	/*�жϲ������Ƿ����*/
	bool isPlayerNull();

private:
	libvlc_instance_t* _pinstance;//ʵ��
	libvlc_media_t* _pmedia;//ý��
	libvlc_media_player_t* _pplayer;//������
	QString _mediaPath;//����·��������
	int _mediaLength;//��λms
	WId _hwnd;//���ھ��
};
