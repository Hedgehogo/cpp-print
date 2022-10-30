#include "IO/Base.hpp"
#include "IO/CalcSystem.hpp"
#include "IO/Vector.hpp"
#include "IO/CArray.hpp"
#include "IO/Array.hpp"
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
	int arr[]{5, 7, 9};
	io::printLn("asgafj", 12749, 8231.0f, io::array(arr), io::Hex{1244});
	io::Output<std::vector<std::string>>::output = printVectorString;
	io::printLn(std::vector<std::string>{"asfg", "ashd", "asfhkaj"});
	std::cout << io::Output<A>{A{10, 15}};
}
