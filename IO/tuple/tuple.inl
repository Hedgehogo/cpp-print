//included into tuple.hpp

namespace io {
	template <typename... ArgsType>
	template <size_t Elem>
	std::enable_if_t<(Elem != 0), void> StreamOutput<std::tuple<ArgsType...>>::outputPart(std::ostream &stream, const std::tuple<ArgsType...> &object) {
		outputPart<Elem - 1>(stream, object);
		stream << ", ";
		Output<std::tuple_element_t<Elem, std::tuple<ArgsType...>>>::output(stream, std::get<Elem>(object));
	}
	
	template <typename... ArgsType>
	template <size_t Elem>
	std::enable_if_t<(Elem == 0), void> StreamOutput<std::tuple<ArgsType...>>::outputPart(std::ostream &stream, const std::tuple<ArgsType...> &object) {
		Output<std::tuple_element_t<Elem, std::tuple<ArgsType...>>>::output(stream, std::get<Elem>(object));
	}
	
	template <typename... ArgsType>
	void StreamOutput<std::tuple<ArgsType...>>::output(std::ostream &stream, const std::tuple<ArgsType...> &object) {
		stream << '{';
		outputPart<std::tuple_size_v<std::tuple<ArgsType...>> - 1>(stream, object);
		stream << '}';
	}
	
	void StreamOutput<std::tuple<>>::output(std::ostream &stream, const std::tuple<> &object) {
		stream << "{}";
	}
}