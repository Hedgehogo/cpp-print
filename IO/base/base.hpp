#pragma once
#include <iostream>
#include <functional>

namespace io {
	class Stream {
	private:
		static std::ostream* ref;
	
	public:
		static void set(std::ostream& ref);
		
		static std::ostream& get();
	};
	
	template <typename Type>
	struct StreamOutput {
		static void output(std::ostream &stream, const Type &object);
	};
	
	template <typename Type>
	struct Output {
		static std::function<void(std::ostream &, const Type &)> output;
		const Type &ref;
	};
	
	template <typename Type>
	void operator<<(std::ostream &stream, const Output<Type> &output);
	
	template <char Delim = ' ', typename Type>
	void print(const Type &first);
	
	template <char Delim = ' ', typename Type, typename... ArgsType>
	void print(const Type &first, const ArgsType &... args);
	
	template <char Delim = ' ', typename... ArgsType>
	void printLn(const ArgsType &... args);
	
	template <typename Type>
	void printDel(const std::string &delim, const Type &first);
	
	template <typename Type, typename... ArgsType>
	void printDel(const std::string &delim, const Type &first, const ArgsType &... args);
	
	template <typename... ArgsType>
	void printDelLn(const std::string &delim, const ArgsType &... args);
	
	template <char Delim = ' ', typename Type>
	void printSt(std::ostream &stream, const Type &first);
	
	template <char Delim = ' ', typename Type, typename... ArgsType>
	void printSt(std::ostream &stream, const Type &first, const ArgsType &... args);
	
	template <char Delim = ' ', typename... ArgsType>
	void printStLn(std::ostream &stream, const ArgsType &... args);
	
	template <typename Type>
	void printStDel(std::ostream &stream, const std::string &delim, const Type &first);
	
	template <typename Type, typename... ArgsType>
	void printStDel(std::ostream &stream, const std::string &delim, const Type &first, const ArgsType &... args);
	
	template <typename... ArgsType>
	void printStDelLn(std::ostream &stream, const std::string &delim, const ArgsType &... args);
}

#include "base.inl"