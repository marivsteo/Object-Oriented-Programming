#include "GUI.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>


FirstGUI::FirstGUI(AdminCSVController& c) : ctrl{ c }
{
	this->initGUI();
	this->populateList();

	QObject::connect(this->addButton, &QPushButton::clicked, this, &FirstGUI::addHandler);
}


FirstGUI::~FirstGUI()
{
}

void FirstGUI::initGUI()
{
	QHBoxLayout* mainLayout = new QHBoxLayout{ this };

	QVBoxLayout* radioLayout = new QVBoxLayout{ this };

	this->sortButton = new QRadioButton{ "sort" };
	this->shuffleButton = new QRadioButton{ "shuffle" };

	radioLayout->addWidget(this->sortButton);
	radioLayout->addWidget(this->shuffleButton);

	

	this->movieList = new QListWidget{};
	radioLayout->addWidget(this->movieList);
	mainLayout->addLayout(radioLayout);

	QVBoxLayout* rightLayout = new QVBoxLayout{};

	QFormLayout* dataLayout = new QFormLayout{};
	this->titleEdit = new QLineEdit{};
	this->genreEdit = new QLineEdit{};
	this->linkEdit = new QLineEdit{};
	this->yearEdit = new QLineEdit{};
	dataLayout->addRow("Title", this->titleEdit);
	dataLayout->addRow("Genre", this->genreEdit);
	dataLayout->addRow("Link", this->linkEdit);
	dataLayout->addRow("Year", this->yearEdit);

	rightLayout->addLayout(dataLayout);
	mainLayout->addLayout(rightLayout);

	QHBoxLayout* buttonsLayout = new QHBoxLayout{};
	this->addButton = new QPushButton{ "Add" };
	this->removeButton = new QPushButton{ "Remove" };
	this->updateButton = new QPushButton{ "Update" };

	buttonsLayout->addWidget(this->addButton);
	buttonsLayout->addWidget(this->removeButton);
	buttonsLayout->addWidget(this->updateButton);

	rightLayout->addLayout(buttonsLayout);

	this->connectSignalsAndSlots();
}

void FirstGUI::connectSignalsAndSlots() {
	QObject::connect(this->sortButton, &QRadioButton::clicked, this, &FirstGUI::sortList);
	QObject::connect(this->shuffleButton, &QRadioButton::clicked, this, &FirstGUI::shuffleList);
}

void FirstGUI::populateList()
{
	this->movieList->clear();

	for (auto& s : this->ctrl.getAll())
	{
		this->movieList->addItem(QString::fromStdString(s.getName() + ", " + s.getGenre() + ", " + s.getTrailer() + ", " + std::to_string(s.getYear())));
	}
}

void FirstGUI::addHandler()
{
	QString title = this->titleEdit->text();
	QString genre = this->genreEdit->text();
	QString link = this->linkEdit->text();
	QString year = this->yearEdit->text();

	this->ctrl.addMovie(title.toStdString(), genre.toStdString(), link.toStdString(), year.toInt());

	this->populateList();
}

void FirstGUI::sortList() {
	this->movieList->clear();

	std::vector<Movie>& elems = this->ctrl.sortMovieTitleAscending();

	for (auto& s : elems)
	{
		this->movieList->addItem(QString::fromStdString(s.getName() + ", " + s.getGenre() + ", " + s.getTrailer() + ", " + std::to_string(s.getYear())));
	}
}

void FirstGUI::shuffleList() {

	//this->ctrl.getAll();

	this->populateList();
}