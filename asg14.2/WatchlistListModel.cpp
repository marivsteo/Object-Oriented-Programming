#include "WatchlistListModel.h"
#include <qcolor.h>
#include <string>

WatchlistModel::WatchlistModel(Controller& controller) : movieController(controller)
{

}

WatchlistModel::~WatchlistModel()
{
}

int WatchlistModel::rowCount(const QModelIndex& parent) const
{
	return this->movieController.getWatchlist().size();
}

int WatchlistModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant WatchlistModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int col = index.column();

	Movie currentMovie = this->movieController.getWatchlist()[row];

	if (role == Qt::DisplayRole)
	{
		switch (col)
		{
		case 0:
			return QString::fromStdString(currentMovie.getName());
		case 1:
			return QString::fromStdString(currentMovie.getGenre());
		case 2:
			return QString::fromStdString(std::to_string(currentMovie.getYear()));
		case 3:
			return QString::fromStdString(std::to_string(currentMovie.getLikes()));
		case 4:
			return QString::fromStdString(currentMovie.getTrailer());
		default:
			break;
		}
	}

	if (role == Qt::BackgroundColorRole)
	{
		if (row % 2 == 0)
			return QColor(206, 142, 142);
	}

	return QVariant();
}

QVariant WatchlistModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
	{
		switch (section)
		{
		case 0:
			return "Name";
		case 1:
			return "Genre";
		case 2:
			return "Year";
		case 3:
			return "Likes";
		case 4:
			return "Trailer";
		}
	}
	return QVariant();
}

bool WatchlistModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (role == Qt::EditRole || role == Qt::DisplayRole)
	{
		Movie& currentMovie = this->movieController.getWatchlist()[index.row()];
		int column = index.column();
		switch (column)
		{
		case 0:
		{
			currentMovie.setName(value.toString().toStdString());
			break;
		}
		case 1:
		{
			currentMovie.setGenre(value.toString().toStdString());
			break;
		}
		case 2:
		{
			currentMovie.setYear(atoi(value.toString().toStdString().c_str()));
			break;
		}
		case 3:
		{
			currentMovie.setLikes(atoi(value.toString().toStdString().c_str()));
			break;
		}
		case 4:
		{
			currentMovie.setTrailer(value.toString().toStdString());
			break;
		}
		}
	}

	emit dataChanged(index, index);
	return true;
}

Qt::ItemFlags WatchlistModel::flags(const QModelIndex& index) const
{
	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}