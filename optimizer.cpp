#include "optimizer.h"

Optimizer::Optimizer(QList<QString> fileContents)
{
	m_status = true; //initially, we're good (hopefully)
	m_fileContents = fileContents; 
	m_linesModified = 0;
	int x = 0; QString *line = NULL;//initialize as null.

	while (!fileContents[x].contains("public class"))
		line = &fileContents[++x];
	m_className = * line;
	m_className = * line;
	m_className.remove("public class ");
	m_className.resize(m_className.indexOf(' '));
}

void Optimizer::optimize()
{
	strengthReduce();
	//TODO: inline(), 
}

void Optimizer::strengthReduce()
{
	//This optimization replaces multiplication/division by multiples of 2 with a bit shift.

	for (int x = 0; x < m_fileContents.size(); ++x)
	{
		//Skip comments, we assume they are denoted by "**"
		if (m_fileContents[x].contains("**"))
			while (!m_fileContents[x++].contains("*/")) { /** just chill **/ }

		if (m_fileContents[x].contains("*"))
		{
			//possible multiplication
			bool ok;
			QString * line = &m_fileContents[x];
			int number = line->mid(line->indexOf('*'), line->indexOf(';')).replace(QString(" "), 
						 QString("")).replace(QString("*"), QString("")).replace(QString(";"), QString("")).toInt(&ok);
			if (ok && number % 2 == 0) {
				//no encoding errors and an even number, so we proceed.
				int shifter = 0;
				while ((number % 2 == 0 || number == 1) && number != 0){ number /= 2; shifter++; }
				shifter--;
				if (number == 0){
					QString shift(" << "); QString num; num.setNum(shifter);
					shift += num; shift += ";";
					line->resize(line->indexOf("*") - 1);
					m_fileContents[x].append(shift);
					m_linesModified++;
				}//power of two

				else if (number > 1) {
					QString shift(" << "); QString num1; QString num2; num1.setNum(number); num2.setNum(++shifter);
					num1 += QString(")");
					line->replace(QString("= "), QString("= ("));
					shift.prepend(num1); shift.prepend(" * "); shift.append(num2); shift.append(";");
					line->resize(line->indexOf("*") - 1);
					m_fileContents[x].append(shift);
					m_linesModified++;
				}
			}
		}

		else if (m_fileContents[x].contains("/") && !m_fileContents[x].contains("//"))
		{
			//possible division
			bool ok; int divider = 0;
			QString * line = &m_fileContents[x];
			int number = line->mid(line->indexOf('/'), line->indexOf(';')).replace(QString(" "), 
						 QString("")).replace(QString("/"), QString("")).replace(QString(";"), QString("")).toInt(&ok);
			while (number % 2 == 0 && number != 0){ 
				number /= 2; divider++;
			}

			if (ok && number == 1) {
				//no encoding errors and an even number, so we proceed.

				QString shift(" >> "); QString num; num.setNum(divider);
				shift += num; shift += ";";
				line->resize(line->indexOf("/") - 1);
				m_fileContents[x].append(shift);
				m_linesModified++;
			}
		}
	}
}

void Optimizer::compile()
{
	optimize();

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

const int & Optimizer::getLinesModified(){ return m_linesModified; }
const QString & Optimizer::getClassName(){ return m_className; }