#include <iostream>
#include <QString>
#include <QFile>
#include <QList>

class Optimizer
{
public:
	Optimizer(QList<QString> fileContents);

	const QList<QString> & getFile();

	void compile();
private:
	void updateFile();
};