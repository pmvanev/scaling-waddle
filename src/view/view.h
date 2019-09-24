#ifndef VIEW_H
#define VIEW_H

#include "observer/observer.hpp"
#include "model/model.hpp"

namespace sw {
namespace view {

class view : public observer {
public:
    virtual void draw() = 0;
private:
    std::shared_ptr<Model> m_model;
};

} // namespace sw
} // namespace view

#endif // VIEW_H