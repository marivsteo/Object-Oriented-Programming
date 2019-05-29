#pragma once
#include "C:\Qt\5.12.3\msvc2017_64\include\QtWidgets\qwidget.h"
#include "AdminCSVController.h"
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlistwidget.h>
#include <QRadioButton>

class FirstGUI :
	public QWidget
{
private:
	AdminCSVController& ctrl;

	QLineEdit* titleEdit, * genreEdit, * linkEdit, * yearEdit;
	QPushButton* addButton, * removeButton, * updateButton;
	QRadioButton* sortButton, * shuffleButton;
	QListWidget* movieList;

public:
	FirstGUI(AdminCSVController& c);
	~FirstGUI();

private:
	void initGUI();
	void populateList();
	void connectSignalsAndSlots();
	void addHandler();

public slots:
	void sortList();
	void shuffleList();
};