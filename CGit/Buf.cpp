#include "CGit.hpp"

namespace Git {
	Buf::Buf(size_t size)
	{
		m_buf.size = size;
		m_buf.asize = 0;
		m_buf.ptr = (char*)malloc(size);
	}

	Buf::~Buf()
	{
		if (m_buf.asize == 0)
		{
			free(m_buf.ptr);
		}
		else
		{
			git_buf_dispose(&m_buf);
		}
		m_buf.ptr = nullptr;
	}

	Buf::operator git_buf* ()
	{
		return &m_buf;
	}
	Buf::operator std::string()
	{
		return std::string(m_buf.ptr);
	}
};