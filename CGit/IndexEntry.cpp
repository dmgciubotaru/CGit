#include "CGit.hpp"
#include "IndexEntry.hpp"

namespace Git
{
	IndexEntry::IndexEntry(const git_index_entry& indexEntry)
		: m_entry(indexEntry)
	{
	}

	std::string IndexEntry::GetPath()
	{
		return m_entry.path;
	}
}