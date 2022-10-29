#include "base.hpp"

namespace io {
	void Stream::set(std::ostream &ref) {
		Stream::ref = &ref;
	}
	
	std::ostream &Stream::get() {
		return *ref;
	}
	
	std::ostream* Stream::ref = &std::cout;
}