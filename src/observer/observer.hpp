#ifndef OBSERVER_HPP
#define OBSERVER_HPP

namespace sw {
namespace observer {

class Observer {
public:
  virtual ~Observer(){};
  virtual void update() = 0;
}; // class Observer

} // namespace sw
} // namespace observer

#endif // OBSERVER_HPP