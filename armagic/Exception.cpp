#include "Exception.h"

Exception::Exception(const std::string& message) {
	message_ = message;
}

Exception::~Exception() { }
