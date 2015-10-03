#include <QTextStream>
#include <cstdlib>

#include "MainThread.h"

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

	Compiler *pCompiler = new Compiler(*asList);
	pCompiler->compile();
	std::cout << "Compile finished. Lines changed: " << pCompiler->getLinesModified() << std::endl;
	delete pCompiler;

	Q_EMIT(finished());
}//end run