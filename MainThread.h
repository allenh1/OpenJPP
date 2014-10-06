#ifndef MAINTHREAD_H
#define MAINTHREAD_H


#include <QObject>

#include "optimizer.h"

class MainThread : public QObject
{
	Q_OBJECT
public:
	MainThread(QObject *parent, int argc, QString argv) : QObject(parent),
															   m_argc(argc),
															   m_argv(argv)
	{ connect(this, SIGNAL(finished()), parent, SLOT(quit())); }

	Q_SIGNAL void finished();

	void run();
private:
	int m_argc;
	QString m_argv;
};
#endif