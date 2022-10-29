//included into cArray.hpp

namespace io {
	template <typename Type, size_t Size>
	void StreamOutput<Array<Type, Size>>::output(std::ostream &stream, const Array<Type, Size> &object) {
		stream << '[';
		if(!std::empty(object.ref)) {
			for(auto iter = std::begin(object.ref); iter != std::end(object.ref) - 1; ++iter) {
				Output<Type>::output(stream, *iter);
				stream << ", ";
			}
			Output<Type>::output(stream, *(std::end(object.ref) - 1));
		}
		stream << ']';
	}
	
	template <typename Type, size_t Size>
	Array<Type, Size> array(const ArrayType<Type, Size> &ref) {
		return Array<Type, Size>{ref};
	}
}