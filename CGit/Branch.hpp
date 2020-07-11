#pragma once

#include "CGit.hpp"

namespace Git
{
	class Branch : public Reference
	{
	public:
		Branch(git_reference* ref);
		Branch(Reference& ref);
		std::string GetName();
		void Delete();
	};
}