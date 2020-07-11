#pragma once

#include "CGit.hpp"

namespace Git
{
	class Buf
	{
	public:
		Buf(size_t size);
		~Buf();
		operator git_buf*();
		operator std::string();
	private:
		git_buf m_buf;
	};
}