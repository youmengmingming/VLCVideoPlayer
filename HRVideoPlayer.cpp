#include "HRVideoPlayer.h"
#include<QFileDialog>
#include<QMessageBox>

HRVideoPlayer::HRVideoPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HRVideoPlayerClass())
	,_currentTime(0)
	,_totalTime(0)
	,_vlcPlayer(0)
	,totalTimer(0)
{
    ui->setupUi(this);
	//this->setWindowFlag(Qt::FramelessWindowHint);
	connect(ui->doubleSpinBox_speed, SIGNAL(valueChanged(double)), this, SLOT(setSpeed(double)));
	connect(ui->hSlider, SIGNAL(sliderMoved(int)), this, SLOT(slotSliderMoved(int)));
}

HRVideoPlayer::~HRVideoPlayer()
{
    delete ui;
}

QString HRVideoPlayer::formatTime(int p_iMilliSeconds)
{
	int ss = 1000;
	int mi = ss * 60;
	int hh = mi * 60;
	int dd = hh * 24;

	long day = p_iMilliSeconds / dd;
	long hour = (p_iMilliSeconds - day * dd) / hh;
	long minute = (p_iMilliSeconds - day * dd - hour * hh) / mi;
	long second = (p_iMilliSeconds - day * dd - hour * hh - minute * mi) / ss;
	long milliSecond = p_iMilliSeconds - day * dd - hour * hh - minute * mi - second * ss;

	QString hou = QString::number(hour, 10);
	QString min = QString::number(minute, 10);
	QString sec = QString::number(second, 10);
	QString msec = QString::number(milliSecond, 10);

	if (hour >= 0 && hour <= 9)
	{
		hou = QString("0") + hou;
	}
	if (minute >= 0 && minute <= 9)
	{
		min = QString("0") + min;
	}
	if (second >= 0 && second <= 9)
	{
		sec = QString("0") + sec;
	}

	return hou + ":" + min + ":" + sec;
}

void HRVideoPlayer::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_F5)
	{
		on_pushButton_play_clicked();
	}
	else if (event->key() == Qt::Key_Escape)
	{
		if (this->isFullScreen())
		{
			on_pushButton_fullScreen_clicked();
			return;
		}
		else return;
	}
	else if (event->key() == Qt::Key_PageUp)
	{
		double dspeed = ui->doubleSpinBox_speed->value();
		dspeed += 0.5;
		ui->doubleSpinBox_speed->setValue(dspeed);
	}
	else if (event->key() == Qt::Key_PageDown)
	{
		double dspeed = ui->doubleSpinBox_speed->value();
		dspeed -= 0.5;
		ui->doubleSpinBox_speed->setValue(dspeed);
	}
	/*else if (event->key() == Qt::Key_Left)
	{
	}*/
}

void HRVideoPlayer::on_pushButton_open_clicked()
{
	if (_vlcPlayer&&!_vlcPlayer->isPlayerNull())
	{
		int ret = QMessageBox::information(this, QString::fromUtf16(u"系统提示"), QString::fromUtf16(u"已经存在可播放的媒体文件，是否重新选择文件？"), QString::fromUtf16(u"确定"), QString::fromUtf16(u"取消"));
		if (ret)
		{
			return;
		}
		else
		{
			on_pushButton_stop_clicked();
		}
	}
	_vlcPlayer = new VlcPlayer(this);
	totalTimer = new QTimer();
	connect(totalTimer, SIGNAL(timeout()), this, SLOT(slotTimeOut()));
	QString path = QFileDialog::getOpenFileName(this, "Choose your file");
	path = QDir::toNativeSeparators(path);//处理路径，路径斜杠方式不正确，会导致媒体创建时无法获取路径，从而返回空指针
	if (path.isEmpty()) return;
	path  = QString::fromUtf16(path.toStdU16String().c_str());//QString的中文字符处理  QString::fromUtf16(u"中文字符");
	_vlcPlayer->setMediaName(path);
	_vlcPlayer->setWId(ui->label_video->winId());
	_vlcPlayer->createPlayer();//这里的功能可以进行进一步的拆分
	_totalTime = _vlcPlayer->getMediaLength();
	ui->hSlider->setMaximum(_totalTime);
	ui->label_end->setText(formatTime(_totalTime));
}

void HRVideoPlayer::on_pushButton_play_clicked()
{
	if (_vlcPlayer->isPlayerNull()) return;
	if (_vlcPlayer->isPlayerPlaying())
	{
		ui->pushButton_play->setText(QString::fromUtf16(u"播放"));
		_vlcPlayer->pauseMedia();
		totalTimer->stop();
	}
	else 
	{
		ui->pushButton_play->setText(QString::fromUtf16(u"暂停"));
		_vlcPlayer->playMedia();
		totalTimer->start(1000);
	}
}

void HRVideoPlayer::on_pushButton_stop_clicked()
{
	_currentTime = 0;
	_totalTime = 0;
	ui->doubleSpinBox_speed->setValue(1.0);
	ui->pushButton_play->setText(QString::fromUtf16(u"播放"));
	_vlcPlayer->stopMedia();
	totalTimer->stop();
	delete totalTimer;
	totalTimer = NULL;
	QString str = formatTime(0);
	ui->label_start->setText(str);
	ui->label_end->setText(str);
	ui->hSlider->setValue(0);
}

void HRVideoPlayer::on_pushButton_fullScreen_clicked()
{
	emit setFullScreen();
	if (this->isFullScreen())
	{
		this->showNormal();
	}
	else
	{
		this->showFullScreen();
		this->setWindowState(Qt::WindowFullScreen);
		this->move(0, 0);
	}
	
}

void HRVideoPlayer::setSpeed(double speed)
{
	_vlcPlayer->setSpeed(speed);
	totalTimer->setInterval(1000 / speed);
}

void HRVideoPlayer::slotSliderMoved(int val)
{
	if (!_vlcPlayer || _vlcPlayer->isPlayerNull())
	{
		ui->hSlider->setValue(0);//滑动归位
		return;
	}
	_vlcPlayer->setJumpTime(val);
	_currentTime = val;
	ui->label_start->setText(formatTime(_currentTime));
}

void HRVideoPlayer::slotTimeOut()
{
	_currentTime += 1000;
	if (_currentTime >= _totalTime)
	{
		ui->label_start->setText(formatTime(_totalTime));
		on_pushButton_play_clicked();
		_currentTime = _totalTime;
		return;
	}
	ui->label_start->setText(formatTime(_currentTime));
	ui->hSlider->setValue(_currentTime);
}
