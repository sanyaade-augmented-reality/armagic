#ifndef ARTOOLKIT_EXCEPTION_H_
#define ARTOOLKIT_EXCEPTION_H_

#include <string>

class Exception
{
public:
	Exception(const std::string& message);
	virtual ~Exception();

	inline std::string getMessage() const { return message_; }

private:
	std::string message_;
};

#endif
