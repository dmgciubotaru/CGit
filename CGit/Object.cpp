#include "CGit.hpp"

namespace Git
{
	Object::Object(git_object* object)
		:m_obj(object)
	{
	}
	Object::Object(Object&& object)
		:m_obj(object.m_obj)
	{
		object.m_obj = nullptr;
	}
	Object::~Object()
	{
	}
	bool Object::IsTree()
	{
		return git_object_type(m_obj) == GIT_OBJECT_TREE;
	}
	Object::operator git_object* ()
	{
		return m_obj;
	}
	Object::operator const git_object* () const
	{
		return m_obj;
	}
}