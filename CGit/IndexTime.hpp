#pragma once

#include "CGit.hpp"

namespace Git
{
	class IndexTime
	{
	public:
		IndexTime(int32_t sec, uint32_t nsec);

		int32_t GetSec();
		void SetSec(int32_t sec);

		uint32_t GetNsec();
		void SetNsec(uint32_t nsec);

	private:
		IndexTime(const git_index_time& indexTime);
		operator git_index_time();


		git_index_time m_indexTime;
	};
};