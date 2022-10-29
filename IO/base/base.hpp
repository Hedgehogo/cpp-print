#pragma once
#include <iostream>
#include <functional>

namespace io {
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
}

#include "base.inl"