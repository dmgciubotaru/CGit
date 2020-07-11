#pragma once

#include "CGit.hpp"

namespace Git
{
	class Object
	{
	public:
		Object(git_object* object);
		Object(Object&& object);
		~Object();

		bool IsTree();

		operator git_object* ();
		operator const git_object* ()const;

	private:
		Object(const Object&) = delete;
		Object& operator=(const Object&) = delete;

		git_object* m_obj;
	};
}