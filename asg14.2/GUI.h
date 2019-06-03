#pragma once
#pragma once
#include "Controller.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <qformlayout.h>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QPalette>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QRadioButton>
#include <QDebug>
#include <QLinearGradient>
#include<qshortcut.h>
#include<qkeysequence.h>
#include <WatchlistListModel.h>
#include <WatchlistWindow.h>

class GUI : public QWidget
{
	Q_OBJECT

private:
	QLabel* moviesLabel;
	QRadioButton* sortedButton, * shuffledButton;
	QPlainTextEdit* repository, * genreList, * watchlist;
	QLineEdit* nameTextbox, * yearTextbox, * genreTextbox, * linkTextbox, * generateTextbox, * removeNameTextbox, * removeGenreTextbox;
	QPushButton* addButton, * updateButton, * removeButton, * playButton, * nextButton, * addGenreButton, * generateButton, * removeLikeButton, * removeDislikeButton, * undoButton, * redoButton, * showWatchlistButton;
	Controller& ctrl;
	QHBoxLayout* mainLayout;
	QGridLayout* repositoryLayout{}, * genreListLayout{}, * watchlistLayout{};
	QShortcut * undoShortcut, * redoShortcut;

	void initGUIRepo();
	void initGUIGenreList();
	void initGUIWatchlist();

	WatchlistModel* watchlistModel;
	WatchlistView* watchlistView;

public:
	GUI(Controller& ctrl_, QWidget* parent);
	~GUI();

	void initGUI();
	void connectSignals();

signals:
	void repositoryModified();
	void watchlistModified();

public slots:
	void sortedList();
	void shuffledList();
	void addRepositoryHandler();
	void RepositoryModify();
	void updateRepositoryHandler();
	void removeRepositoryHandler();
	void playHandler();
	void nextHandler();
	void addGenreHandler();
	void generateHandler();
	void watchlistModify();
	void removeLikeHandler();
	void removeDislikeHandler();
	void undoHandler();
	void redoHandler();

	void handleShowWatchlist();
};