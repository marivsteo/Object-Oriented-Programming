#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_asg12GUI.h"

class asg12GUI : public QMainWindow
{
	Q_OBJECT

public:
	asg12GUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::asg12GUIClass ui;
};
