//included into map.hpp

namespace io {
	template <typename Key, typename Value>
	void StreamOutput<std::pair<Key, Value>>::output(std::ostream &stream, const std::pair<Key, Value> &object) {
		Output<Key>::output(stream, object.first);
		stream << ": ";
		Output<Value>::output(stream, object.second);
	}
	
	template <typename Key, typename Value>
	void StreamOutput<std::map<Key, Value>>::output(std::ostream &stream, const std::map<Key, Value> &object) {
		stream << '[';
		if(!object.empty()) {
			for(auto iter = object.begin(); iter != --object.end(); ++iter) {
				Output<std::pair<Key, Value>>::output(stream, *iter);
				stream << ", ";
			}
			Output<std::pair<Key, Value>>::output(stream, *--object.end());
		}
		stream << ']';
	}
}