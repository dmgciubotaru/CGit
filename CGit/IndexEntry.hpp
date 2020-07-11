#pragma once

#include "CGit.hpp"

namespace Git
{
	class IndexEntry
	{
	public:
		IndexEntry(const git_index_entry &indexEntry);

		std::string GetPath();

	private:
		git_index_entry m_entry;
	};
}