#pragma once

#include "..\include\libgit2\git2.h"

#define CHECK(x) {if(x){throw Git::Exception();}}

namespace Git {
	class Exception;
	class Buf;
	
	class Repository;
	
	class Reference;
	class Branch;

	class Index;
	class IndexTime;
	class IndexEntry;

	class Object;
}


#include "Exception.hpp"
#include "Buf.hpp"

#include "Repository.hpp"

#include "Reference.hpp"
#include "Branch.hpp"

#include "Index.hpp"
#include "IndexTime.hpp"
#include "IndexEntry.hpp"

#include "Object.hpp"