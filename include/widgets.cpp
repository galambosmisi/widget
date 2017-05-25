#include "widgets.hpp"
#include "graphics.hpp"

using namespace genv;

Widget::Widget(Window * parent, int x, int y, int sx, int sy, bool selectable)
{
    _parent=parent;
    _x=x;
    _y=y;
    _size_x = sx;
    _size_y = sy;
    _selected=false;
    _selectable=selectable;
}

bool Widget::is_hover(int mouse_posx, int mouse_posy) const
{
    return mouse_posx < _x+_size_x && mouse_posx > _x && mouse_posy < _y+_size_y && mouse_posy > _y;
}

bool Widget::is_selected() const
{
    return _selected;
}

bool Widget::is_selectable() const
{
    return _selectable;
}

void Widget::set_selected(bool selected)
{
    _selected=selected;
}

void Widget::set_selectable(bool selectable)
{
    _selectable=selectable;
}

string Widget::cut_title(string title, int size_x) const
{
    string s = title;
    if(gout.twidth(title) > size_x-8)
    {
        s=title+"...";
        while(gout.twidth(s) > size_x-8)
        {
                title.pop_back();
                s=title+"...";
        }
        if(s[s.size()-1]==' ')
        {
            title.pop_back();
            s=title+"...";
        }
    }
    return s;
}

void Widget::draw() const {}
void Widget::handle(genv::event ev) {}
void Widget::get_data(ostream & datafile) const {}
