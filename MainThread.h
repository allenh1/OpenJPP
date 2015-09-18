#ifndef MAINTHREAD_H
#define MAINTHREAD_H


#include <QtCore>
#include <QObject>
#include <QThread>
#include "optimizer.h"

class MainThread : public QObject
{
	Q_OBJECT
public:
	MainThread(int argc, QString argv, QObject * parent = 0) :
	    m_argc(argc),
		m_argv(argv),
		QObject(parent)
	{
		asList = new QList<QString>();
		m_pThread = new QThread();
		this->moveToThread(m_pThread);
		// connect(this, &MainThread::finished, m_pThread, &QThread::wait);
		connect(m_pThread, &QThread::started, this, &MainThread::run);
	}

	Q_SIGNAL void finished();

	Q_SLOT void run();

	void start(){ m_pThread->start(); }
private:
	int m_argc;
	QString m_argv;
	QThread * m_pThread;
	QList<QString> *asList;
};
#endif