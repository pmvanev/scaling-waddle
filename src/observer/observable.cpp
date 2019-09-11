#include "observable.hpp"
#include "observer_exception.hpp"

#include <algorithm>

namespace sw {
namespace observer {

void Observable::updateObservers(void) {
  for (auto &observer : m_observers) {
    observer->update();
  }
}

void Observable::addObserver(std::shared_ptr<Observer> observer) {
  if (observer == nullptr) {
    throw NullObserverException("Cannot add null observer.")
  }
  m_observers.push_back(observer);
}

bool Observable::removeObserver(std::shared_ptr<Observer> observer) {
  if (observer == nullptr) {
    throw NullObserverException("Cannot add null observer.")
  }
  auto it = std::find(m_observers.begin(), m_observers.end(), observer);
  if (it == m_observers.end()) {
    return false;
  }
  m_observers.erase(it);
  return true;
}

} // namespace observer
} // namespace sw
