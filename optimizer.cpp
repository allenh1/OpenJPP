#include "optimizer.h"

Optimizer::Optimizer(QList<QString> fileContents)
{
	m_status = true; //initially, we're good (hopefully)
	m_fileContents = fileContents; 

	int x = 0; QString *line = NULL;//initialize as null.

	while (!fileContents[x].contains("public class"))
		line = &fileContents[++x];
	m_className = * line;
	m_className = * line;
	m_className.remove("public class ");
	m_className.resize(m_className.indexOf(' '));
}

void Optimizer::compile()
{
	QString filename = m_className;
	filename = filename.append(".java");
	filename.prepend("/tmp/");

	QFile file(filename);

	m_status = system("pwd > .dir") && m_status;
	QFile dir(".dir");
	if (!dir.open(QIODevice::ReadOnly))
	{
		std::cout << "ERROR: check writing permissions.";
		return;
	}
	QTextStream dirName(&dir);
	const QString directory = dirName.readLine();
	dirName.flush(); dir.close();
	m_status = system("rm -f .dir") && m_status; //delete the file - doesn't really need to be there, does it?
	//m_status = m_status && system("cd /tmp"); //go into the temporary directory for compile phase.

	if (!file.open(QIODevice::WriteOnly))
	{
		std::cout << "ERROR: check writing permissions.\n";
		return;
	}//end if

	QTextStream stream(&file);

	for (int x = 0; x < m_fileContents.size(); ++x)
		stream << m_fileContents[x] + "\n";

	stream.flush();
	file.close();

	QString compileCommand = "javac " + filename;
	QString moveCommand = "mv ";
	//std::cout << "Running command: " << compileCommand.toStdString() << "\n";
	QString classFile = "/tmp/" + m_className + ".class";
	moveCommand.append(classFile); moveCommand.append(" "); moveCommand.append(directory);
	const char * command1 = compileCommand.toStdString().c_str();
	const char * command2 = moveCommand.toStdString().c_str();
	m_status = system(command1) && m_status; //compile the file
	m_status = system(command2) && m_status;
	if (m_status)
		std::cout<<"Warning: errors may have occured.\n";
}