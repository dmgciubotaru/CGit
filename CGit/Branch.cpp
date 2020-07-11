#include "Branch.hpp"
#pragma once

namespace Git {
	Branch::Branch(git_reference* ref)
		: Reference(ref)
	{

	}

	Branch::Branch(Reference& ref)
		: Reference(std::forward<Reference>(ref))
	{
	}

	std::string Branch::GetName()
	{
		const char* name;
		git_branch_name(&name, m_ref);
		return name;
	}
	void Branch::Delete()
	{
		CHECK(git_branch_delete(m_ref));
		git_reference_free(m_ref);
		m_ref = nullptr;
	}
}