#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/log/attributes/mutable_constant.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>

/* I ripped this off from
 * https://stackoverflow.com/questions/24750218/boost-log-to-print-source-code-file-name-and-line-number
 */

namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace expr = boost::log::expressions;
namespace src = boost::log::sources;
namespace keywords = boost::log::keywords;

// New macro that includes severity, filename and line number
#define CUSTOM_LOG(lg, sev)                                                    \
  BOOST_LOG_STREAM_WITH_PARAMS(                                                \
      (lg),                                                                    \
      (sw::logger::set_get_attrib("File",                                      \
                                  sw::logger::path_to_filename(__FILE__)))(    \
          sw::logger::set_get_attrib("Line", __LINE__))(                       \
          ::boost::log::keywords::severity = (boost::log::trivial::sev)))

#define SW_LOG(sev) CUSTOM_LOG(sw::logger::lg, sev)

namespace sw {
namespace logger {
// Set attribute and return the new value
template <typename ValueType>
ValueType set_get_attrib(const char *name, ValueType value);
src::severity_logger<logging::trivial::severity_level> lg;
void init();
std::string path_to_filename(std::string path);
}
}
