#pragma once
#include <tuple>
#include "../base/base.hpp"

namespace io {
	template <typename... ArgsType>
	struct StreamOutput<std::tuple<ArgsType...>> {
		template<size_t Elem>
		static std::enable_if_t<(Elem != 0), void> outputPart(std::ostream &stream, const std::tuple<ArgsType...> &object);
		
		template<size_t Elem>
		static std::enable_if_t<(Elem == 0), void> outputPart(std::ostream &stream, const std::tuple<ArgsType...> &object);
		
		static void output(std::ostream &stream, const std::tuple<ArgsType...> &object);
	};
	
	template<>
	struct StreamOutput<std::tuple<>> {
		static void output(std::ostream &stream, const std::tuple<> &object);
	};
}

#include "tuple.inl"
