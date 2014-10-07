#include "optimizer.h"

Optimizer::Optimizer(QList<QString> fileContents){ m_fileContents = fileContents; }

void Optimizer::compile()
{
	const QString filename = "generated.java";

	QFile file(filename);

	if (file.exists())
		system("rm -f generated.java");

	if (!file.open(QIODevice::WriteOnly))
	{
		std::cout << "ERROR: check writing permissions.";
		return;
	}//end if

	QTextStream stream(&file);

	for (int x = 0; x < m_fileContents.size(); ++x)
		stream << m_fileContents[x] + "\n";

	stream.flush();
	file.close();

	system("javac generated.java"); //compile the file
	system("rm -f generated.java"); //delete the file
}