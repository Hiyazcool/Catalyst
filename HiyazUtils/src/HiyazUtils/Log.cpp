#include <stdio.h>
#include "Log.h"
namespace HiyazUtils {

	Logger::Logger() {

	}
	LogPriority Logger::CurrentPriority = Info;
	void Logger::SetPriority(LogPriority _priority) {
		CurrentPriority = _priority;
	}
};