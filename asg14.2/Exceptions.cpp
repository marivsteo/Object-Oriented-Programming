#include "Exceptions.h"

ValidatorException::ValidatorException(std::string _msg) : std::runtime_error{ _msg } {}

RepositoryException::RepositoryException(std::string _msg) : std::runtime_error{ _msg } {}

ControllerException::ControllerException(std::string _msg) : std::runtime_error{ _msg } {}

std::string ValidatorException::message() const noexcept
{
	std::string result{ "Validator Exception: " };

	result += std::runtime_error::what();
	return result;
}

std::string RepositoryException::message() const noexcept
{
	std::string result{ "Repository Exception: " };

	result += std::runtime_error::what();
	return result;
}

std::string ControllerException::message() const noexcept
{
	std::string result{ "Controller Exception: " };

	result += std::runtime_error::what();
	return result;
}