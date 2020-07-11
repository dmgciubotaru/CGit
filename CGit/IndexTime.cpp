#include "CGit.hpp"

namespace Git
{
	IndexTime::IndexTime(int32_t sec, uint32_t nsec)
	{
		m_indexTime.seconds = sec;
		m_indexTime.nanoseconds = nsec;
	}

	int32_t IndexTime::GetSec()
	{
		return m_indexTime.seconds;
	}

	void IndexTime::SetSec(int32_t sec)
	{
		m_indexTime.seconds = sec;
	}

	uint32_t IndexTime::GetNsec()
	{
		return m_indexTime.nanoseconds;
	}

	void IndexTime::SetNsec(uint32_t nsec)
	{
		m_indexTime.nanoseconds = nsec;
	}

	IndexTime::IndexTime(const git_index_time& indexTime)
	{
		m_indexTime = indexTime;
	}

	IndexTime::operator git_index_time()
	{
		return m_indexTime;
	}

};