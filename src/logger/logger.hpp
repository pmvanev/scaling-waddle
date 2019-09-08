#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <memory>
#include <string>

#define SW_LOG(level, msg) sw::log::g_logger->log(sw::log::LogLevel::level, msg)
#define SW_LOG_INIT(level, file_name)                                          \
  sw::log::init(sw::log::LogLevel::level, file_name)

// TODO: use proper logger eventually

namespace sw {
namespace log {

enum class LogLevel {
  debug = 0,
  info = 1,
  warn = 2,
  error = 3,
  critical = 4,
  fatal = 5
};

class Logger {
public:
  Logger(LogLevel level, std::string file_name);
  ~Logger();
  void log(LogLevel level, std::string msg);

private:
  LogLevel m_log_level;
  std::ofstream m_ofstream;
};

extern std::unique_ptr<Logger> g_logger;

void init(LogLevel level, std::string file_name);
}
}

#endif