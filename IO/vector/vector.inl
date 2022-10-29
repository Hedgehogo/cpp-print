//included into vector.hpp

namespace io {
	template <typename Type>
	void StreamOutput<std::vector<Type>>::output(std::ostream &stream, const std::vector<Type> &object) {
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