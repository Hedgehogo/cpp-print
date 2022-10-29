//included into base.hpp

namespace io {
	template <typename Type>
	void StreamOutput<Type>::output(std::ostream &stream, const Type &object) {
		Stream::get() << object;
	};
	
	template <typename Type>
	std::function<void(std::ostream &, const Type &)> Output<Type>::output = StreamOutput<Type>::output;
	
	template <typename Type>
	void operator<<(std::ostream &stream, const Output<Type> &output) {
		output.output(stream, output.ref);
	}
	
	template <char Delim, typename Type>
	void print(const Type &first) {
		Output<Type>::output(Stream::get(), first);
	}
	
	template <char Delim, typename Type, typename... ArgsType>
	void print(const Type &first, const ArgsType &... args) {
		Output<Type>::output(Stream::get(), first);
		Stream::get() << Delim;
		print<Delim>(args...);
	}
	
	template <char Delim, typename... ArgsType>
	void printLn(const ArgsType &... args) {
		print<Delim>(args..., '\n');
	}
	
	template <typename Type>
	void printDel(const std::string &delim, const Type &first) {
		Output<Type>::output(Stream::get(), first);
	}
	
	template <typename Type, typename... ArgsType>
	void printDel(const std::string &delim, const Type &first, const ArgsType &... args) {
		Output<Type>::output(Stream::get(), first);
		Stream::get() << delim;
		printDel(delim, args...);
	}
	
	template <typename... ArgsType>
	void printDelLn(const std::string &delim, const ArgsType &... args) {
		printDel(delim, args..., '\n');
	}
	
	template <char Delim, typename Type>
	void printSt(std::ostream &stream, const Type &first) {
		Output<Type>::output(stream, first);
	}
	
	template <char Delim, typename Type, typename... ArgsType>
	void printSt(std::ostream &stream, const Type &first, const ArgsType &... args) {
		Output<Type>::output(stream, first);
		stream << Delim;
		printSt<Delim>(stream, args...);
	}
	
	template <char Delim, typename... ArgsType>
	void printStLn(std::ostream &stream, const ArgsType &... args) {
		printSt<Delim>(stream, args..., '\n');
	}
	
	template <typename Type>
	void printStDel(std::ostream &stream, const std::string &delim, const Type &first) {
		Output<Type>::output(stream, first);
	}
	
	template <typename Type, typename... ArgsType>
	void printStDel(std::ostream &stream, const std::string &delim, const Type &first, const ArgsType &... args) {
		Output<Type>::output(stream, first);
		stream << delim;
		printStDel(stream, delim, args...);
	}
	
	template <typename... ArgsType>
	void printStDelLn(std::ostream &stream, const std::string &delim, const ArgsType &... args) {
		printStDel(stream, delim, args..., '\n');
	}
}
