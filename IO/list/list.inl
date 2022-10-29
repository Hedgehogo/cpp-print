//included into list.hpp

namespace io {
	template <typename Type>
	void StreamOutput<std::list<Type>>::output(std::ostream &stream, const std::list<Type> &object) {
		stream << '[';
		if(!object.empty()) {
			for(auto iter = object.begin(); iter != --object.end(); ++iter) {
				Output<Type>::output(stream, *iter);
				stream << ", ";
			}
			Output<Type>::output(stream, *--object.end());
		}
		stream << ']';
	}
}