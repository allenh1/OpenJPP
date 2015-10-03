#ifndef COMPILER_H
#define COMPILER_H

#include <QTextStream>
#include <iostream>
#include <QString>
#include <QFile>
#include <QList>

struct jpp_pointer {
	QString type_name;
	QString java_class;
};

class Compiler
{
public:
	Compiler(QList<QString> fileContents);
	~Compiler(){ delete m_pDataTypes; }

	const QList<QString> & getFile();
	const QString & getClassName();
	void compile();

	const int & getLinesModified();
private:
	bool m_status;
	int m_linesModified;

	QString m_className;
	QList<QString> m_fileContents;
	QList<jpp_pointer> * m_pDataTypes;

	bool isDataType(QString * line);

	const QString & getDataType(QString * line);
	const QString & getJavaClass(QString * line);

	void process();
	void convertPointers();
	void strengthReduce();
};
#endif