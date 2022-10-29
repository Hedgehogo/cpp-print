#pragma once
#include <map>
#include "../base/base.hpp"

namespace io {
	template <typename Key, typename Value>
	struct StreamOutput<std::pair<Key, Value>> {
		static void output(std::ostream &stream, const std::pair<Key, Value> &object);
	};
	
	template <typename Key, typename Value>
	struct StreamOutput<std::map<Key, Value>> {
		static void output(std::ostream &stream, const std::map<Key, Value> &object);
	};
}

#include "map.inl"