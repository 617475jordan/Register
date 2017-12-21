#include "register.h"
#include <QtWidgets/QApplication>
void                     fileIsOver();//ÎÄ¼þ¼Ð´æÔÚÅÐ¶Ï


int main(int argc, char *argv[])
{
	fileIsOver();
	QApplication a(argc, argv);
	Register w;
	w.show();
	return a.exec();
}
void fileIsOver()
{
	string dir = "data";
	if (access(dir.c_str(), 0) == -1)
	{
		//cout << dir << " is not existing" << endl;
		//cout << "now make it" << endl;
#ifdef WIN32  
		int flag = mkdir(dir.c_str());
#endif  
#ifdef linux   
		int flag = mkdir(dir.c_str(), 0777);
#endif  
		/*if (flag == 0)
		{
		cout << "make successfully" << endl;
		}
		else {
		cout << "make errorly" << endl;
		}*/
	}
	else
	{
		return;
	}
}