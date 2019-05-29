#pragma once
#ifndef ASG8_9_DBREPOSITORY_H
#define ASG8_9_DBREPOSITORY_H


#include "Movie.h"
#include <sqlite3.h>
#include "PersistentRepository.h"


class DbRepository : virtual protected PersistentRepository<Movie> {
private:
	sqlite3* db{};

	void load() override;

	void save() override;
public:

	explicit DbRepository(const std::string& path);

	~DbRepository();
};


#endif //ASG8_9_DBREPOSITORY_H