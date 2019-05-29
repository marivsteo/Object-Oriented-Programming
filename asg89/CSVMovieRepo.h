#include <utility>
#include "MovieRepository.h"
#include "CSVRepository.h"

#ifndef  CSV_MOV_REPO
#define CSV_MOV_REPO
class CSVMovieRepo : public CSVRepository<Movie>, public MovieRepository {
public:
	explicit CSVMovieRepo(const std::string& filename) : CSVRepository(filename) {
	}
};
#endif