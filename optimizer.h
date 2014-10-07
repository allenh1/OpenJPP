#include <iostream>
#include <QString>
#include <QFile>
#include <QList>
#include <QTextStream>

class Optimizer
{
public:
	Optimizer(QList<QString> fileContents);
	~Optimizer(){}

	const QList<QString> & getFile();

	void compile();
private:
	void updateFile();
	QList<QString> m_fileContents;
};