#pragma once

#include <QPlainTextEdit>
#include <QString>
#include <string>

class QPlainTextEditRepository : public QPlainTextEdit
{
public:
	QPlainTextEditRepository(QString str);
	~QPlainTextEditRepository();

public slots:
	void shuffleRepository();
};