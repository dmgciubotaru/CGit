#include "Exception.hpp"
#pragma once

#include "CGit.hpp"

namespace Git {

	Exception::Exception()
		:std::runtime_error(giterr_last()->message)
	{

	}

	Exception::Exception(const std::string& error)
		:std::runtime_error(error.c_str())
	{

	}
}
