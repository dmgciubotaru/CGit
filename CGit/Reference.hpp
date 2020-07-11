#pragma once

#include "CGit.hpp"

namespace Git
{
	class Reference
	{
	public:
		Reference(Reference&& ref);
		~Reference();

		bool IsBranch();
		bool IsNote();
		bool IsRemote();
		bool IsTag();

		std::string GetName() const;

		Branch AsBranch();


	protected:
		git_reference* m_ref;
		Reference(git_reference* ref);
	private:
		Reference& operator = (const Reference&) = delete;
		Reference(const Reference&) = delete;
		friend class Repository;
	};
}