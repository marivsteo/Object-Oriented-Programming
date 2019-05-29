#ifndef ASG8_9_DB_MOV_REPO_H
#define ASG8_9_DB_MOV_REPO_H

#include "DbRepository.h"
#include "MovieRepository.h"
#include <string>

class DbMovieRepo : public DbRepository, public MovieRepository {
public:
	explicit DbMovieRepo(const std::string& filename) : DbRepository(filename) {}
};

#endif //ASG8_9_DBREPOSITORY_H