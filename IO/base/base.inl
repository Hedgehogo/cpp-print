//included into base.hpp

namespace io {
	template <typename Type>
	void StreamOutput<Type>::output(std::ostream &stream, const Type &object) {
		std::cout << object;
	};
	
	template <typename Type>
	std::function<void(std::ostream &, const Type &)> Output<Type>::output = StreamOutput<Type>::output;
	
	template <typename Type>
	void operator<<(std::ostream &stream, const Output<Type> &output) {
		output.output(stream, output.ref);
	}
	
	template <char Delim, typename Type>
	void print(const Type &first) {
		Output<Type>::output(std::cout, first);
	}
	
	template <char Delim, typename Type, typename... ArgsType>
	void print(const Type &first, const ArgsType &... args) {
		Output<Type>::output(std::cout, first);
		std::cout << Delim;
		print<Delim>(args...);
	}
	
	template <char Delim, typename... ArgsType>
	void printLn(const ArgsType &... args) {
		print<Delim>(args..., '\n');
	}
	
	template <typename Type>
	void printDel(const std::string &delim, const Type &first) {
		Output<Type>::output(std::cout, first);
	}
	
	template <typename Type, typename... ArgsType>
	void printDel(const std::string &delim, const Type &first, const ArgsType &... args) {
		Output<Type>::output(std::cout, first);
		std::cout << delim;
		printDel(delim, args...);
	}
	
	template <typename... ArgsType>
	void printDelLn(const std::string &delim, const ArgsType &... args) {
		printDel(delim, args..., '\n');
	}
}
