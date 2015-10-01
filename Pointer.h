#include <QString>
#include <QTextStream>
#include <QList>

class Pointer
{
public:
	Pointer(QList<QString> fileContents);
	~Pointer(){}

	const QList<QString> & getFile();

	
}