#include "GUI.h"

void GUI::initGUI()
{
	this->setWindowTitle("Movies");
	this->mainLayout = new QHBoxLayout{ this };

	this->initGUIRepo();
	this->initGUIGenreList();
	this->initGUIWatchlist();

	this->mainLayout->addLayout(this->repositoryLayout);
	this->mainLayout->addLayout(this->genreListLayout);
	this->mainLayout->addLayout(this->watchlistLayout);

	this->connectSignals();

}

void GUI::connectSignals()
{
	QObject::connect(this->sortedButton, &QRadioButton::clicked, this, &GUI::sortedList);
	QObject::connect(this->shuffledButton, &QRadioButton::clicked, this, &GUI::shuffledList);

	QObject::connect(this, &GUI::repositoryModified, this, &GUI::RepositoryModify);

	QObject::connect(this->addButton, &QPushButton::clicked, this, &GUI::addRepositoryHandler);
	QObject::connect(this->removeButton, &QPushButton::clicked, this, &GUI::removeRepositoryHandler);
	QObject::connect(this->updateButton, &QPushButton::clicked, this, &GUI::updateRepositoryHandler);

	QObject::connect(this->playButton, &QPushButton::clicked, this, &GUI::playHandler);
	QObject::connect(this->nextButton, &QPushButton::clicked, this, &GUI::nextHandler);
	QObject::connect(this->addGenreButton, &QPushButton::clicked, this, &GUI::addGenreHandler);
	QObject::connect(this->generateButton, &QPushButton::clicked, this, &GUI::generateHandler);

	QObject::connect(this->removeLikeButton, &QPushButton::clicked, this, &GUI::removeLikeHandler);
	QObject::connect(this->removeDislikeButton, &QPushButton::clicked, this, &GUI::removeDislikeHandler);

	QObject::connect(this, &GUI::watchlistModified, this, &GUI::watchlistModify);
}

void GUI::shuffledList()
{
	this->repository->clear();
	QString str = QString::fromStdString(this->ctrl.printMovies());
	this->repository->insertPlainText(str);
}

void GUI::removeLikeHandler()
{
	QString name = this->removeNameTextbox->text();
	QString genre = this->removeGenreTextbox->text();
	this->removeNameTextbox->clear();
	this->removeGenreTextbox->clear();
	this->ctrl.removeFromWatchlist(name.toStdString(), genre.toStdString(), "like");
	emit watchlistModified();
	emit repositoryModified();
}

void GUI::removeDislikeHandler()
{
	QString name = this->removeNameTextbox->text();
	QString genre = this->removeGenreTextbox->text();
	this->removeNameTextbox->clear();
	this->removeGenreTextbox->clear();
	this->ctrl.removeFromWatchlist(name.toStdString(), genre.toStdString(), "dislike");
	emit watchlistModified();
	emit repositoryModified();
}

void GUI::generateHandler()
{
	this->genreList->clear();
	QString genre = this->generateTextbox->text();
	this->ctrl.generateListByGenres(genre.toStdString());
	QString newGenreList = QString::fromStdString(this->ctrl.printListByGenres());
	this->genreList->insertPlainText(newGenreList);
}

void GUI::playHandler()
{
	this->ctrl.trailerOnListByGenre();
}

void GUI::addGenreHandler()
{
	this->ctrl.addToWatchlist();
	emit watchlistModified();
}

void GUI::watchlistModify()
{
	this->watchlist->clear();
	QString watchlist_str = QString::fromStdString(this->ctrl.printWatchlist());
	this->watchlist->insertPlainText(watchlist_str);
}

void GUI::nextHandler()
{
	this->ctrl.nextTrailerOnListByGenre();
}

void GUI::addRepositoryHandler()
{
	QString name = this->nameTextbox->text();
	QString genre = this->genreTextbox->text();
	QString year = this->yearTextbox->text();
	int year_ = year.toInt();
	QString link = this->linkTextbox->text();

	if (this->ctrl.addMovie(name.toStdString(), genre.toStdString(), year_, 1, link.toStdString()) == true)
	{
		this->nameTextbox->clear();
		this->genreTextbox->clear();
		this->yearTextbox->clear();
		this->linkTextbox->clear();
		emit repositoryModified();
	}
}

void GUI::removeRepositoryHandler()
{
	QString name = this->nameTextbox->text();
	QString genre = this->genreTextbox->text();

	this->nameTextbox->clear();
	this->genreTextbox->clear();
	this->yearTextbox->clear();
	this->linkTextbox->clear();

	if (this->ctrl.removeMovie(name.toStdString(), genre.toStdString()) == true)
	{
		this->nameTextbox->clear();
		this->genreTextbox->clear();
		this->yearTextbox->clear();
		this->linkTextbox->clear();
		emit repositoryModified();
	}
}

void GUI::updateRepositoryHandler()
{
	QString name = this->nameTextbox->text();
	QString genre = this->genreTextbox->text();
	QString year = this->yearTextbox->text();
	int year_ = year.toInt();
	QString link = this->linkTextbox->text();

	this->nameTextbox->clear();
	this->genreTextbox->clear();
	this->yearTextbox->clear();
	this->linkTextbox->clear();

	if (this->ctrl.updateMovie(name.toStdString(), genre.toStdString(), year_, 1, link.toStdString()) == true)
	{
		this->nameTextbox->clear();
		this->genreTextbox->clear();
		this->yearTextbox->clear();
		this->linkTextbox->clear();
		emit repositoryModified();
	}
}

void GUI::RepositoryModify()
{
	this->repository->clear();
	QString str;
	if (this->sortedButton->isChecked())
		str = QString::fromStdString(this->ctrl.printSortedMovies());
	else
		str = QString::fromStdString(this->ctrl.printMovies());
	this->repository->insertPlainText(str);
}

void GUI::sortedList()
{
	this->repository->clear();
	QString str = QString::fromStdString(this->ctrl.printSortedMovies());
	this->repository->insertPlainText(str);
}


void GUI::initGUIRepo()
{
	this->repositoryLayout = new QGridLayout;

	this->moviesLabel = new QLabel{ "List of movies" };
	this->repositoryLayout->addWidget(this->moviesLabel, 0, 0, 1, 1);

	

	QString movies_string_qt = QString::fromStdString(this->ctrl.printMovies());
	this->repository = new QPlainTextEdit{ movies_string_qt };
	this->repository->setFont(QFont("Helvetica", 10, 10, true));
	this->repositoryLayout->addWidget(this->repository, 2, 0, 2, 1);

	QHBoxLayout* radioButtons = new QHBoxLayout;
	this->shuffledButton = new QRadioButton("Shuffled");
	this->sortedButton = new QRadioButton("Sorted");
	radioButtons->addWidget(sortedButton);
	radioButtons->addWidget(shuffledButton);
	this->repositoryLayout->addItem(radioButtons, 4, 0, 12, 1);

	QFormLayout* interactions = new QFormLayout{};
	this->nameTextbox = new QLineEdit{};
	QLabel* nameLabel = new QLabel{ "&Name:" };
	nameLabel->setBuddy(this->nameTextbox);
	this->genreTextbox = new QLineEdit{};
	QLabel* genreLabel = new QLabel{ "&Genre:" };
	genreLabel->setBuddy(this->genreTextbox);
	this->yearTextbox = new QLineEdit{};
	QLabel* yearLabel = new QLabel{ "&Year:" };
	yearLabel->setBuddy(this->yearTextbox);
	this->linkTextbox = new QLineEdit{};
	QLabel* linkLabel = new QLabel{ "&Link:" };
	linkLabel->setBuddy(this->linkTextbox);
	interactions->addRow(nameLabel, this->nameTextbox);
	interactions->addRow(genreLabel, this->genreTextbox);
	interactions->addRow(yearLabel, this->yearTextbox);
	interactions->addRow(linkLabel, this->linkTextbox);
	this->repositoryLayout->addLayout(interactions, 16, 0, 6, 1);

	QVBoxLayout* first_buttons = new QVBoxLayout;
	this->addButton = new QPushButton{ "Add" };
	this->updateButton = new QPushButton{ "Update" };
	this->removeButton = new QPushButton{ "Remove" };
	first_buttons->addWidget(this->addButton);
	first_buttons->addWidget(this->updateButton);
	first_buttons->addWidget(this->removeButton);
	this->repositoryLayout->addLayout(first_buttons, 23, 0, 2, 1);

	QLinearGradient buttonGradient(0, 0, 0, this->repository->height());
	buttonGradient.setColorAt(0, QColor(206, 142, 142));
	buttonGradient.setColorAt(1, QColor(240, 183, 183));
	QPalette palette = this->repository->palette();

	palette.setBrush(QPalette::Base, buttonGradient);
	palette.setBrush(QPalette::Highlight, buttonGradient);
	palette.setBrush(QPalette::HighlightedText, Qt::white);
	palette.setBrush(QPalette::Text, Qt::white);

	this->repository->setPalette(palette);
}

void GUI::initGUIGenreList()
{
	this->genreListLayout = new QGridLayout;

	QLabel* movies = new QLabel{ "Movies with this genre" };
	this->genreListLayout->addWidget(movies, 0, 0, 1, 1);

	this->genreList = new QPlainTextEdit{ "" };
	this->genreList->setFont(QFont("Helvetica", 10, 10, true));
	this->genreListLayout->addWidget(this->genreList, 2, 0, 14, 1);

	QVBoxLayout* first_buttons = new QVBoxLayout;
	this->playButton = new QPushButton{ "Play" };
	this->nextButton = new QPushButton{ "Next" };
	this->addGenreButton = new QPushButton{ "Add" };
	first_buttons->addWidget(this->playButton);
	first_buttons->addWidget(this->nextButton);
	first_buttons->addWidget(this->addGenreButton);

	QHBoxLayout* genreLayout = new QHBoxLayout;
	this->generateButton = new QPushButton{ "Show" };
	this->generateTextbox = new QLineEdit;
	genreLayout->addWidget(this->generateButton);
	genreLayout->addWidget(this->generateTextbox);
	first_buttons->addLayout(genreLayout);

	this->genreListLayout->addLayout(first_buttons, 16, 0, 2, 1);
}

void GUI::initGUIWatchlist()
{
	this->watchlistLayout = new QGridLayout;

	QLabel* movies = new QLabel{ "Watchlist" };
	this->watchlistLayout->addWidget(movies, 0, 0, 1, 1);

	this->watchlist = new QPlainTextEdit{ "" };
	this->watchlist->setFont(QFont("Helvetica", 10, 10, true));
	this->watchlistLayout->addWidget(this->watchlist, 2, 0, 10, 1);

	QHBoxLayout* buttons = new QHBoxLayout;
	this->removeLikeButton = new QPushButton{ "Like" };
	this->removeDislikeButton = new QPushButton{ "Dislike" };
	buttons->addWidget(removeLikeButton);
	buttons->addWidget(removeDislikeButton);

	this->watchlistLayout->addItem(buttons, 12, 0, 2, 1);
	QFormLayout* interactions = new QFormLayout{};
	this->removeNameTextbox = new QLineEdit{  };
	QLabel* nameLabel = new QLabel{ "&Name:" };
	nameLabel->setBuddy(this->removeNameTextbox);
	//this->watchlistLayout->addWidget(removeNameTextbox, 14, 0, 2, 1);

	this->removeGenreTextbox = new QLineEdit{  };
	QLabel* genreLabel = new QLabel{ "&Genre:" };
	genreLabel->setBuddy(this->removeGenreTextbox);
	//this->watchlistLayout->addWidget(removeGenreTextbox, 16, 0, 2, 1);
	interactions->addRow(nameLabel, this->removeNameTextbox);
	interactions->addRow(genreLabel, this->removeGenreTextbox);
	this->watchlistLayout->addLayout(interactions, 16, 0, 6, 1);
}

GUI::GUI(Controller& ctrl_, QWidget* parent = 0) : QWidget{ parent }, ctrl{ ctrl_ }
{
}


GUI::~GUI()
{
}