#include <QCoreApplication>
#include "MainThread.h"

int main(int argc, char *argv[])
{
	QCoreApplication a (argc, argv);
	QString filename(argv[1]);

	MainThread * pThread = new MainThread(&a, argc, filename);

	pThread->run();

	return 0;
}