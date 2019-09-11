#ifndef OBSERVER_EXCEPTION_H
#define OBSERVER_EXCEPTION_H

#include <stdexcept>

namespace sw {
namespace observer_exception {
class NullObserverException : public std::runtime_error {};
} // namespace observer_exception
} // namespace sw

#endif OBSERVER_EXCEPTION_H