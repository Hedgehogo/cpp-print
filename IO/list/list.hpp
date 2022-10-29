#pragma once
#include <list>
#include "../base/base.hpp"

namespace io {
	template <typename Type>
	struct StreamOutput<std::list<Type>> {
		static void output(std::ostream &stream, const std::list<Type> &object);
	};
}

#include "list.inl"