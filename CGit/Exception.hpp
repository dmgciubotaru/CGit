#pragma once

#include <stdexcept>

namespace Git
{

	class Exception : public std::runtime_error
	{
	public:
		Exception();
		Exception(const std::string& error);
	};

};