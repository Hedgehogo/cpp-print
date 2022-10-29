#pragma once
#include <array>
#include "../base/base.hpp"

namespace io {
	template <typename Type, size_t Size>
	struct StreamOutput<std::array<Type, Size>> {
		static void output(std::ostream &stream, const std::array<Type, Size> &object);
	};
}

#include "array.inl"
