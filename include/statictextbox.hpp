#ifndef STATICTEXTBOX_HPP_INCLUDED
#define STATICTEXTBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

using namespace genv;

class StaticTextBox : public Widget {
protected:
    string _title, _pos;
    bool _boxed;
    color _text_color, _back_color, _aline_color, _pline_color;
    color _line_color;

public:
    StaticTextBox(Window * parent, int x, int y, int sx, int sy, bool selectable, string pos, string title, bool boxed);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual void set_title(string title);
    virtual string get_title() const;
};

#endif // STATICTEXTBOX_HPP_INCLUDED
