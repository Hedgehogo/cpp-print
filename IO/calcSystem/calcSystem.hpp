#pragma once
#include "../base/base.hpp"

namespace io {
	struct Hex { const int& num; };
	
	template <>
	struct StreamOutput<Hex> {
		static void output(std::ostream &stream, const Hex &object);
	};
	
	struct Dec { const int& num; };
	
	template <>
	struct StreamOutput<Dec> {
		static void output(std::ostream &stream, const Dec &object);
	};
	
	struct Oct { const int& num; };
	
	template <>
	struct StreamOutput<Oct> {
		static void output(std::ostream &stream, const Oct &object);
	};
}