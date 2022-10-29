#pragma once
#include <vector>
#include "../base/base.hpp"

namespace io {
	template <typename Type>
	struct StreamOutput<std::vector<Type>> {
		static void output(std::ostream &stream, const std::vector<Type> &object);
	};
}

#include "vector.inl"