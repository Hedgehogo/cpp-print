//included into array.hpp

namespace io {
	template <typename Type, size_t Size>
	void StreamOutput<std::array<Type, Size>>::output(std::ostream &stream, const std::array<Type, Size> &object) {
		stream << '[';
		if(!object.empty()) {
			for(auto iter = object.begin(); iter != object.end() - 1; ++iter) {
				Output<Type>::output(stream, *iter);
				stream << ", ";
			}
			Output<Type>::output(stream, *(object.end() - 1));
		}
		stream << ']';
	}
}