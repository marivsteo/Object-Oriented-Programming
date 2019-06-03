#pragma once

#include <QWidget>
#include "ui_WatchListView.h"

class WatchlistView : public QWidget
{
	Q_OBJECT
private:
	QAbstractItemModel* model;
public:
	WatchlistView(QAbstractItemModel* model, QWidget* parent = Q_NULLPTR);
	~WatchlistView();

private:
	Ui::Watchlist ui;
};
