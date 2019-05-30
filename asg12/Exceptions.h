#pragma once

#include <exception>
#include <stdexcept>
#include <string>

class ValidatorException : public std::runtime_error
{
public:
	ValidatorException(std::string _msg);
	std::string message() const noexcept;
};

class RepositoryException : public std::runtime_error
{
public:
	RepositoryException(std::string _msg);
	std::string message() const noexcept;
};

class ControllerException : public std::runtime_error
{
public:
	ControllerException(std::string _msg);
	std::string message() const noexcept;
};