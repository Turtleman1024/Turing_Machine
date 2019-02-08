#ifndef _CRASH_H_
#define _CRASH_H_

#include <stdexcept>
#include <string>

using namespace std;

class crash : public runtime_error
{
	public:
	crash(string reason);
};


#endif /* _CRASH_H_ */