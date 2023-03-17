#include "VlcPlayer.h"
#include<QMessageBox>

VlcPlayer::VlcPlayer(QObject *parent)
	: QObject(parent)
	,_pinstance(0)
	,_pmedia(0)
	,_pplayer(0)
	,_mediaPath("")
	,_mediaLength(0)
	,_hwnd(0)
{
}

VlcPlayer::~VlcPlayer()
{}

void VlcPlayer::setMediaName(QString mediaName)
{
	_mediaPath = mediaName;
}

void VlcPlayer::createPlayer()
{
	_pinstance = libvlc_new(0, NULL);//����ý��ʵ��
	libvlc_media_release(_pmedia);//�������δ�����ý��
	_pmedia = libvlc_media_new_path(_pinstance, _mediaPath.toStdString().c_str());
	if (!_pmedia) return;  //���������쳣���������ָ�����
	_pplayer = libvlc_media_player_new_from_media(_pmedia);
	if (!_pplayer) return;//���������쳣���������ָ�����
	libvlc_media_parse(_pmedia);
	libvlc_time_t  time_t = libvlc_media_get_duration(_pmedia);
	_mediaLength = time_t;
	libvlc_media_player_set_hwnd(_pplayer, (void*)_hwnd);
}

void VlcPlayer::playMedia()
{
	if (!_pplayer || !_pinstance)
	{
		return;
	}
		libvlc_media_player_play(_pplayer);
}

void VlcPlayer::pauseMedia()
{
	if (!_pplayer || !_pinstance)
	{
		return;
	}
	libvlc_media_player_pause(_pplayer);
}

void VlcPlayer::stopMedia()
{
	if (!_pplayer || !_pinstance)
	{
		return;
	}
	libvlc_media_player_stop(_pplayer);
	libvlc_media_player_release(_pplayer);
	libvlc_media_release(_pmedia);
	libvlc_release(_pinstance);
	_pinstance = NULL;
	_pmedia = NULL;
	_pplayer = NULL;
}

int VlcPlayer::getMediaLength()
{
	return _mediaLength;
}

void VlcPlayer::setWId(WId id)
{
	_hwnd = id;
}

void VlcPlayer::setSpeed(int speed)
{
	if (!_pplayer) return;	
	libvlc_media_player_set_rate(_pplayer, speed);
}

void VlcPlayer::setJumpTime(int time)
{
	if (!_pplayer) return;
	libvlc_media_player_set_time(_pplayer, time);
}

bool VlcPlayer::isPlayerPlaying()
{
	if (!_pplayer) return false;
	if (libvlc_media_player_is_playing(_pplayer)) return true;
	else return false;
}

bool VlcPlayer::isPlayerAble()/*���񲻿��ã������÷������⣿*/
{
	if (!_pplayer) return false;
	bool a = libvlc_media_player_will_play(_pplayer);
	return a;
}

bool VlcPlayer::isPlayerNull()
{
	if (_pplayer) return false;
	else return true;
}
