#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "window.hpp"
#include "graphics.hpp"

using namespace std;
using namespace genv;


class Window;

class Widget
{
protected:
    Window * _parent;
    int _x, _y, _size_x, _size_y;
    bool _selected;
    bool _selectable;

public:
    Widget(Window * parent, int x, int y, int sx, int sy, bool selectable);
    virtual bool is_hover(int mouse_posx, int mouse_posy) const;
    virtual bool is_selected() const ;
    virtual bool is_selectable() const;
    virtual void draw() const;
    virtual void set_selected(bool selected);
    virtual void set_selectable(bool selectable);
    virtual void handle(genv::event ev);
    virtual void get_data(ostream & datafile, int i) const;
    virtual string cut_title(string title, int size_x) const;
};


#endif // WIDGETS_HPP_INCLUDED
