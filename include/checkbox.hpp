#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <functional>

using namespace genv;

class CheckBox : public Widget
{
protected:
    bool _checked;
    std::function<void()> _action;
    color _back_color, _aline_color, _pline_color;
    color _line_color;
public:
    CheckBox(Window * parent, int x, int y, int sx, int sy, bool selectable, std::function<void()> action);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() const ;
    virtual void set_action(std::function<void()> action);
    virtual void set_selected(bool selected);
    virtual void get_data(ostream & datafile) const;
};

#endif // EXAMPLECHECKBOX_HPP_INCLUDED
