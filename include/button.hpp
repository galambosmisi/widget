#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <functional>

using namespace genv;

class Button : public Widget
{
protected:
    string _title, _pos;
    bool _center_title;
    bool _pushed;
    std::function<void()> _action;
    color _back_color, _text_color, _line_color;

public:
    Button(Window * parent,int x, int y, int sx, int sy, bool selectable, string pos, string title, std::function<void()> action);
    virtual void draw() const;
    virtual void handle(genv::event ev);
    virtual void set_action(std::function<void()> action);
    virtual string get_title() const;
    virtual void set_title_(string title);
    virtual void set_pushed(bool pushed);
    virtual void get_data(ostream & datafile) const;
};

#endif // BUTTON_HPP_INCLUDED
