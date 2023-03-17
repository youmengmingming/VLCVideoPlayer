#include"HRVideoPlayer.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	HRVideoPlayer* hr = new HRVideoPlayer();
	hr->show();
	return a.exec();
}