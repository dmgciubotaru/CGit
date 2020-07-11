#pragma once

#include "CGit.hpp"

namespace Git
{
	class Index
	{
	public:
		Index(git_index* index);
		Index(Index&& index);
		~Index();

		std::vector<IndexEntry> GetEntries();

	private:
		Index(const Index&) = delete;
		Index& operator=(const Index&) = delete;
		git_index* m_index;
	};
};