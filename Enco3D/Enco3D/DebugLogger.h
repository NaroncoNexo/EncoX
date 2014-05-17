#ifndef _ENCO3D_DEBUGLOGGER_H_
#define _ENCO3D_DEBUGLOGGER_H_

#include <string>
#include <fstream>
#include <iostream>

namespace Enco3D
{
	namespace Core
	{
		enum DebugLoggerFlag : unsigned int
		{
			WriteToConsole,
			WriteToFile,

			NumDebugLoggerFlags
		};

		class DebugLogger
		{
		private:
			static bool s_flags[NumDebugLoggerFlags];
			static std::ofstream s_outputStream;

		public:
			static void init();
			static void deinit();

			static void log(const std::string &text);

			static void setFlag(unsigned int flag, bool enabled) { s_flags[flag] = enabled; }
			static bool isFlagEnabled(unsigned int flag) { return s_flags[flag]; }
		};
	}
}

#endif