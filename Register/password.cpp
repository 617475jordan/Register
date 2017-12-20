#include "password.h"
#include "AES.h"
#include <fstream>

#define random(x) (rand() % x) //通过取余取得指定范围的随机数
password::password()
{
}


password::~password()
{
}

std::vector<int> password::createPassword()
{
	int length = 128;
	std::vector<int> m_vecOutput(length);
	std::ifstream m_infile("data\\password.index", std::ios::in);
	if (!m_infile.is_open())
	{
		return m_vecOutput;
	}
	std::string m_strLineData;
	std::string m_password;
	while (getline(m_infile, m_strLineData))
	{
		m_password=m_password+m_strLineData;
		m_strLineData.clear();
	}
	m_infile.close();
	AES *m_aes = new AES();
	m_password = m_aes->DecryptionAES(m_password,1);
	m_aes = NULL;
	delete[] m_aes;
	
	for (int i = 0; i < length; i++)
	{
		bool flag = false;
		while (flag == false)
		{
			m_vecOutput[i] = RandomChar();
			if ((m_vecOutput[i] % (m_password[i] - 47) == 0 || m_vecOutput[i] % (m_password[i] - 64) == 0))
			{
				flag = true;
			}
		}
	}
	return m_vecOutput;
}

bool password::CheckTheChar(int AsciiChar)
{
	if ((AsciiChar >= 48 && AsciiChar <= 57) || (AsciiChar >= 65 && AsciiChar <= 90) || (AsciiChar >= 97 && AsciiChar <= 122))
		return true;
	else
		return false;
}

inline int password::RandomChar()
{
	int Num;
	do
	{
		Num = random(122);
	} while (CheckTheChar(Num) == false);
	return Num;
}


