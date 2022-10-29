#include "IO/Base.hpp"
#include "IO/CalcSystem.hpp"
#include "IO/Vector.hpp"
#include "IO/Tuple.hpp"
#include "IO/List.hpp"
#include "IO/Map.hpp"

class A {
public:
	int a, b;
	
	A(int a, int b) : a(a), b(b) {
	}
};

template <>
struct io::StreamOutput<A> {
	static void output(std::ostream &stream, const A &object) {
		printDel("", '{', object.a, ", ", object.b, '}');
	};
};

static void printVectorString(std::ostream &stream, const std::vector<std::string> &object) {
	for(const auto &item: object) {
		io::print(item, ' ');
	}
};

int main() {
	io::printLn("asgafj", 12749, 8231.0f, std::tuple<char, int>{'b', 7}, io::Hex{64});
	io::Output<std::vector<std::string>>::output = printVectorString;
	io::printLn(std::vector<std::string>{"asfg", "ashd", "asfhkaj"});
	std::cout << io::Output<A>{A{10, 15}};
}
