#include "logger.hpp"

/* I ripped this off from
 * https://stackoverflow.com/questions/24750218/boost-log-to-print-source-code-file-name-and-line-number
 */

namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace expr = boost::log::expressions;
namespace src = boost::log::sources;
namespace keywords = boost::log::keywords;

namespace sw {
namespace logger {

src::severity_logger<logging::trivial::severity_level> lg;

// Convert file path to only the filename
std::string path_to_filename(std::string path) {
  return path.substr(path.find_last_of("/\\") + 1);
}

void init() {
  // New attributes that hold filename and line number
  logging::core::get()->add_thread_attribute(
      "File", attrs::mutable_constant<std::string>(""));
  logging::core::get()->add_thread_attribute("Line",
                                             attrs::mutable_constant<int>(0));

  logging::add_file_log(
      keywords::file_name = "sample.log",
      keywords::format =
          (expr::stream << expr::format_date_time<boost::posix_time::ptime>(
                               "TimeStamp", "%Y-%m-%d_%H:%M:%S.%f")
                        << ": <" << boost::log::trivial::severity << "> " << '['
                        << expr::attr<std::string>("File") << ':'
                        << expr::attr<int>("Line") << "] " << expr::smessage));
  logging::add_common_attributes();
}

} // namespace logger
} // namespace cw