#include <QCoreApplication>
#include "MainThread.h"

int main(int argc, char *argv[])
{
	QCoreApplication a (argc, argv);
	QString filename(argv[1]);

	MainThread * pThread = new MainThread(argc, filename);
	pThread->start();
	a.connect(pThread, &MainThread::finished, &a, &QCoreApplication::quit);
	return a.exec();
}