#pragma once

#include "CGit.hpp"

#include <string>
#include <vector>

namespace Git
{
	class Repository
	{
	public:
		Repository(const std::string& path);

		std::vector<Branch> GetBranches(bool getRemote = true, bool getLocal = true);
		void CheckoutTree(const Object& object);
		Reference GetRef(const std::string& name);
		Branch GetBranch(const std::string& name, bool local=true);
		Object GetObject(const std::string& name);
		Reference GetHead();
		void SetHead(const Reference& ref);
		Index GetIndex();

		static std::string Discover(const std::string& path);
	private:
		git_repository* m_repo;
	};
}