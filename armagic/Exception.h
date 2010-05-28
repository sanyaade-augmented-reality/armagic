#ifndef ARTOOLKIT_EXCEPTION_H_
#define ARTOOLKIT_EXCEPTION_H_

#include <string>

class Exception
{
public:
	Exception(const std::string& message);
	virtual ~Exception();

private:
	std::string message_;
};

#endif
