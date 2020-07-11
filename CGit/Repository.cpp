#include "CGit.hpp"

namespace Git {

	Repository::Repository(const std::string& path)
		:m_repo(nullptr)
	{
		CHECK(git_repository_open(&m_repo, Discover(path).c_str()));
	}

	std::string Repository::Discover(const std::string& path)
	{
		Buf buf(1024);
		CHECK(git_repository_discover(buf, path.c_str(), 0, NULL));
		return buf;
	}
	std::vector<Branch> Repository::GetBranches(bool getRemote, bool getLocal)
	{
		std::vector<Branch> branches;
		
		git_reference* ref;
		git_branch_iterator* iter;
		git_branch_t type = git_branch_t(
			(getLocal ? GIT_BRANCH_LOCAL : 0) |
			(getRemote ? GIT_BRANCH_REMOTE : 0));

		CHECK(git_branch_iterator_new(&iter, m_repo, type));
		
		while (!git_branch_next(&ref, &type, iter))
		{
			branches.push_back(ref);
		}

		git_branch_iterator_free(iter);

		return branches;
	}
	void Repository::CheckoutTree(const Object& object)
	{
		git_checkout_options options = GIT_CHECKOUT_OPTIONS_INIT;
		CHECK(git_checkout_tree(m_repo, object, &options));
	}
	Reference Repository::GetRef(const std::string& name)
	{
		git_reference* ref;
		CHECK(git_reference_lookup(&ref, m_repo, name.c_str()));
		return ref;
	}
	Branch Repository::GetBranch(const std::string& name, bool local)
	{
		git_reference* ref;
		CHECK(git_branch_lookup(&ref, m_repo, name.c_str(), local ? GIT_BRANCH_LOCAL : GIT_BRANCH_REMOTE));
		return ref;
	}
	Object Repository::GetObject(const std::string& name)
	{
		git_object* obj;
		CHECK(git_revparse_single(&obj, m_repo, name.c_str()));
		return obj;
	}
	Reference Repository::GetHead()
	{
		git_reference* ref;
		CHECK(git_repository_head(&ref, m_repo));
		return ref;
	}
	void Repository::SetHead(const Reference& ref)
	{
		CHECK(git_repository_set_head(m_repo, ref.GetName().c_str()));
	}
	Index Repository::GetIndex()
	{
		git_index* index;
		CHECK(git_repository_index(&index, m_repo));
		return index;
	}
}