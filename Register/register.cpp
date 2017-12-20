#include "register.h"
#include "password.h"
#include <time.h>
#include<fstream>
#include "AES.h"
Register::Register(QWidget *parent)
	: QMainWindow(parent)
{
	initalize();
	ui.setupUi(this);
	
}

Register::~Register()
{

}

void Register::initalize()
{
	std::ifstream m_infile("data\\data.index", std::ios::in );
	if (!m_infile.is_open())
	{
		m_infile.close();
		std::ofstream m_outfile("data\\data.index", std::ios::out);
		m_outfile.close();
	}
	else
	{
		std::string m_strLineData;
		while (getline(m_infile, m_strLineData))
		{
			m_passwordData.push_back(m_strLineData);
		}
		m_infile.close();
	}
	QMessageBox::information(this, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("��ʼ���ɹ�"));

}

std::string Register::currentTime()
{
	time_t  m_currentTime;
	m_currentTime = time(0);
	char m_charCurrentTime[100];
	strftime(m_charCurrentTime, sizeof(m_charCurrentTime), "%Y-%m-%d %X %A ", localtime(&m_currentTime));
	return m_charCurrentTime;
}

void Register::outputShow(QString m_qstr)
{
	auto workCursor = ui.outputPlainTextEdit->textCursor();
	workCursor.movePosition(QTextCursor::End);

	workCursor.insertText(m_qstr);
	workCursor.insertBlock();

	QScrollBar *scrollbar = ui.outputPlainTextEdit->verticalScrollBar();

	if (scrollbar)
	{
		scrollbar->setValue(scrollbar->maximum());
	}
	scrollbar = NULL;
	delete[] scrollbar;
}

bool Register::outPutPassword(std::string m_password)
{
	std::ofstream m_outfile("data\\data.index",  std::ios_base::app);
	if (!m_outfile.is_open())
	{
		m_outfile.open("data\\data.index", std::ios::out);
	}
	m_outfile << m_password << endl;
	m_outfile.close();
	return true;
}

void Register::on_clickedPushButton_clicked()
{
	ui.outputPlainTextEdit->clear();
	password *m_password = new password();
	std::vector<int> m_inputData;
	m_inputData = m_password->createPassword();
	char m_outPutPassword[128];
	if (m_inputData.size() < 128)//���볤��
	{
		m_password = NULL;
		delete[] m_password;
		return;
	}
	for (int i = 0; i < m_inputData.size(); i++)
	{
		//if (i>0 && i % 4 == 0)
		//{
		//	m_outPutPassword = m_outPutPassword /*+ "-"*/;
		//}

		m_outPutPassword [i]= (char)m_inputData[i];
		
	}
	for (int i = 0; i < m_passwordData.size(); i++)
	{
		if (m_outPutPassword == m_passwordData[i]  /*||m_outPutPassword.length()<128*/)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("��������Ч"));
			return;
		}
	}
	AES *m_aes = new AES();
	
	std::string m_outPutResult = m_aes->EncryptionAES(m_outPutPassword, 0);
	m_aes = NULL;
	delete[] m_aes;
	if (!outPutPassword(m_outPutResult))
	{
		return;
	}
	QString m_qstr = QString::fromStdString(m_outPutResult);
	outputShow(m_qstr);
	m_password = NULL;
	delete[] m_password;
	m_inputData.clear();
	m_outPutResult.clear();
	m_qstr.clear();
}

void Register::on_clearPushButton_clicked()
{
	ui.outputPlainTextEdit->clear();
}