#include "CGit.hpp"


namespace Git
{
	Index::Index(git_index* index)
		: m_index(index)
	{

	}

	Index::Index(Index&& index)
		: m_index(index.m_index)
	{
		index.m_index = nullptr;
	}

	Index::~Index()
	{
		if (m_index != nullptr)
		{
			git_index_free(m_index);
		}
	}
	std::vector<IndexEntry> Index::GetEntries()
	{
		std::vector<IndexEntry> entries;

		git_index_iterator *iter;
		const git_index_entry* entry;
		CHECK(git_index_iterator_new(&iter, m_index));
		
		while (!git_index_iterator_next(&entry, iter))
		{
			entries.push_back(*entry);
		}

		git_index_iterator_free(iter);

		return entries;
	}
}