#include "checkbox.hpp"
#include "graphics.hpp"
#include <sstream>

using namespace genv;

CheckBox::CheckBox(Window * parent, int x, int y, int sx, int sy, bool selectable, function<void()> action = []() {})
    : Widget(parent, x, y, sx, sy, selectable), _back_color(parent->back_), _aline_color(parent->aline_), _pline_color(parent->pline_), _line_color(parent->pline_)
{
    _checked=false;
    _action=action;
    _parent->push_item(this);
}

void CheckBox::draw() const
{
    gout << move_to(_x, _y) << _line_color << box(_size_x, _size_y);
    gout << move_to(_x+1, _y+1) << _back_color << box(_size_x-2, _size_y-2);
    if (_checked)
    {
        gout << _pline_color;
        gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
    }
}

void CheckBox::set_selected(bool selected)
{
    _selected=selected;
    if(selected) _line_color = _aline_color;
    else _line_color = _pline_color;
}

void CheckBox::handle(genv::event ev)
{

    if (ev.type == ev_key && (ev.keycode == -key_enter || ev.keycode == ' '))
    {
        _checked = !_checked;
        _action();

    }
    if (ev.type == ev_mouse && is_hover(ev.pos_x, ev.pos_y) && ev.button==-btn_left)
    {
        _checked = !_checked;
        _action();
    }
}

void CheckBox::set_action(function<void()> action)
{
    _action=action;
}

bool CheckBox::is_checked() const
{
    return _checked;
}

void CheckBox::get_data(ostream & datafile, int i) const
{
    datafile <<"----"<<i<<"----"<< endl << "A jelölő értéke: " << _checked << endl <<"----"<<i<<"----"<< endl << endl;
}
