#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED


#include "widgets.hpp"
#include "graphics.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace genv;

class Widget;

class Window {
protected:
    vector<Widget*> widgets;
    bool _run;
    int focus;
    const int _XX, _YY;
    string _name;

public:
    color back_, text_, aline_, pline_;
    color back_ground;
    Window(string name, int XX, int YY, color back_color, color text_color, color aline_color, color pline_color, color bg_color);
    virtual void event_loop();
    virtual void push_item(Widget * w);
    virtual void set_run(bool run);
    virtual void clear_screen() const;
    virtual int get_XX() const;
    virtual int get_YY() const;
};

#endif // WINDOW_HPP_INCLUDED
