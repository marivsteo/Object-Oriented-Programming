#include "QtGUI.h"

QtGUI::QtGUI(Controller& controller, QWidget* parent)
	: QMainWindow(parent), controller(controller)
{
	ui.setupUi(this);
	populateList();

	connect(ui.ShowSymptomsButton, SIGNAL(released()), this, SLOT(handleShowSymptoms()));

}

void QtGUI::populateList()
{
	for (auto disorder : this->controller.getAllDisorders())
		ui.disorderData->addItem(QString::fromStdString(disorder.toString()));
}


void QtGUI::handleShowSymptoms()
{
	std::string name = ui.nameEdit->text().toStdString();
	std::vector<Disorder> disorderList = controller.getDisorderByName(name);
	ui.symptomsData->clear();

	for (auto disorder : disorderList)
		ui.symptomsData->addItem(QString::fromStdString(disorder.getSymptoms()));
}