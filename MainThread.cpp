#include "MainThread.h"
#include <QTextStream>
#include <cstdlib>

void MainThread::run()
{
	if (m_argv != "")
	{
		QFile file(m_argv);
		if (!file.open(QIODevice::ReadOnly))
			return;

		QTextStream in (&file);
		QList<QString> asList;
		int x = 0;

		while (!in.atEnd()) {
			asList.push_back(in.readLine());
			std::cout << asList.at(x++).toStdString() << "\n";
		}
	}

	Q_EMIT(finished());
}//end run