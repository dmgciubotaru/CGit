
#include "CGit.hpp"

namespace Git
{
	Reference::Reference(git_reference* ref)
	{
		m_ref = ref;
	}

	Reference::Reference(Reference&& ref)
	{
		m_ref = ref.m_ref;
		ref.m_ref = nullptr;
	}

	Reference::~Reference()
	{
		if (m_ref != nullptr)
		{
			git_reference_free(m_ref);
		}
	}
	bool Reference::IsBranch()
	{
		return git_reference_is_branch(m_ref);
	}
	bool Reference::IsNote()
	{
		return git_reference_is_note(m_ref);
	}
	bool Reference::IsRemote()
	{
		return git_reference_is_remote(m_ref);
	}
	bool Reference::IsTag()
	{
		return git_reference_is_tag(m_ref);
	}
	std::string Reference::GetName() const
	{
		return git_reference_name(m_ref);
	}
	Branch Reference::AsBranch()
	{
		if (!IsBranch())
		{
			throw Exception("Reference not a branch");
		}
		return *this;
	}
}