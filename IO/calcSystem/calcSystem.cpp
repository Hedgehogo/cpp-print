#include "calcSystem.hpp"

namespace io {
	void StreamOutput<Hex>::output(std::ostream &stream, const Hex &object) {
		std::cout << std::hex << object.num << std::dec;
	};
	
	void StreamOutput<Dec>::output(std::ostream &stream, const Dec &object) {
		std::cout << std::dec << object.num;
	};
	
	void StreamOutput<Oct>::output(std::ostream &stream, const Oct &object) {
		std::cout << std::oct << object.num << std::dec;
	};
}
