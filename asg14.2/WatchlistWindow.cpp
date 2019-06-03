#include "WatchlistWindow.h"
#include "Movie.h"
#include "WatchlistListModel.h"



WatchlistView::WatchlistView(QAbstractItemModel* model, QWidget* parent)
	: QWidget(parent), model{ model }
{
	ui.setupUi(this);
	this->ui.watchlistData->setModel(this->model);
}

WatchlistView::~WatchlistView()
{
}
