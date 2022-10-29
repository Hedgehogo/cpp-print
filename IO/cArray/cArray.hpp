#pragma once
#include "../base/base.hpp"

namespace io {
	template <typename Type, size_t Size>
	using ArrayType = Type[Size];
	
	template <typename Type, size_t Size>
	struct Array {
		const ArrayType<Type, Size> &ref;
	};
	
	template <typename Type, size_t Size>
	struct StreamOutput<Array<Type, Size>> {
		static void output(std::ostream &stream, const Array<Type, Size> &object);
	};
	
	template <typename Type, size_t Size>
	Array<Type, Size> array(const ArrayType<Type, Size> &ref);
}

#include "cArray.inl"