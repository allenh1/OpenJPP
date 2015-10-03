#include <iostream>
#include <QString>
#include <QFile>
#include <QList>
#include <QTextStream>

class Compiler
{
public:
	Compiler(QList<QString> fileContents);
	~Compiler(){ delete m_dataTypes; }

	const QList<QString> & getFile();

	void compile();

	const int & getLinesModified();
	const QString & getClassName();
private:
	bool m_status;
	int m_linesModified;

	QString m_className;
	QList<QString> m_fileContents;
	QList<QString> * m_dataTypes;

	void process();
	void convertPointers();
	void strengthReduce();
};