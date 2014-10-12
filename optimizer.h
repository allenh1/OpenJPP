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

	const QString & getClassName();
private:
	bool m_status;
	int linesModified;

	QString m_className;
	QList<QString> m_fileContents;

	void updateFile();
};