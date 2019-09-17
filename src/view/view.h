#ifndef VIEW_H
#define VIEW_H

#include "observer/observer.h"

namespace sw {
namespace view {

class view : public observer {
    public:
    virtual void draw() = 0;
};

} // namespace sw
} // namespace view

#endif // VIEW_H