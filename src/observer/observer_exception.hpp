#ifndef OBSERVER_EXCEPTION_H
#define OBSERVER_EXCEPTION_H

#include <stdexcept>

namespace sw {
namespace observer {
class NullObserverException : public std::runtime_error {
public:
  NullObserverException(const char* msg) : std::runtime_error(msg){};
};
} // namespace observer_exception
} // namespace sw

#endif // OBSERVER_EXCEPTION_H