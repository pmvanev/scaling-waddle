#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include "observer.hpp"
#include <memory>
#include <vector>

namespace sw {
namespace observer {

class Observable {
public:
  virtual ~Observable();
  virtual void updateObservers(void);
  void addObserver(std::shared_ptr<Observer> observer);
  bool removeObserver(std::shared_ptr<Observer> observer);

private:
  std::vector<std::shared_ptr<Observer>> m_observers;
}; // class Observable

} // namespace observer
} // namespace sw

#endif // OBSERVABLE_HPP
