#ifndef REGISTER_H
#define REGISTER_H

#include <QtWidgets/QMainWindow>
#include "ui_register.h"
#include <opencv2.4.10_all.h>
#include <qt_all_vs2013_x86.h>

class Register : public QMainWindow
{
	Q_OBJECT

public:
	Register(QWidget *parent = 0);
	~Register();

private:
	void initalize();
	std::string currentTime();
	void  outputShow(QString m_qstr);
	bool  outPutPassword(std::string m_password);
private:
	Ui::RegisterClass ui;
	std::vector<std::string>   m_passwordData;
private slots:
void on_clickedPushButton_clicked();
void on_clearPushButton_clicked();
};

#endif // REGISTER_H
