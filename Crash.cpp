#include <stdexcept>
#include <string>

#include "Crash.h"

using namespace std;

crash::crash(string reason):
	runtime_error(reason.c_str())
	{
	}
