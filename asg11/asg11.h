#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_asg11.h"

class asg11 : public QMainWindow
{
	Q_OBJECT

public:
	asg11(QWidget *parent = Q_NULLPTR);

private:
	Ui::asg11Class ui;
};
