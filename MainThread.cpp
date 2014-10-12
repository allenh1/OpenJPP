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
		//int x = 0;

		while (!in.atEnd())
			asList->push_back(in.readLine());
	}

	Optimizer *pOptimizer = new Optimizer(*asList);
	pOptimizer->compile();
	std::cout << "Compile finished. Lines changed: " << pOptimizer->getLinesModified() << "\n";
	delete pOptimizer;

	Q_EMIT(finished());
}//end run