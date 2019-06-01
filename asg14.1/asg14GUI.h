#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_asg14GUI.h"

class asg14GUI : public QMainWindow
{
	Q_OBJECT

public:
	asg14GUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::asg14GUIClass ui;
};
