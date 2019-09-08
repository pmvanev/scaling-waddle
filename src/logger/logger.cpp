#include "logger.hpp"

namespace sw {
namespace log {

std::unique_ptr<Logger> g_logger;

void init(LogLevel level = LogLevel::info, std::string file_name = "log.txt") {
  g_logger = std::make_unique<Logger>(level, file_name);
}

Logger::Logger(LogLevel level, std::string file_name) : m_log_level(level) {
  m_ofstream.open(file_name);
}

void Logger::log(LogLevel level, std::string msg) {
  if (level >= m_log_level) {
    m_ofstream << msg << std::endl;
  }
}

Logger::~Logger() { m_ofstream.close(); }
}
}