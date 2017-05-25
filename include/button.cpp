#include "button.hpp"
#include "graphics.hpp"

using namespace genv;

Button::Button(Window * parent,int x, int y, int sx, int sy, bool selectable, string pos, string title, function<void()> action = []() {})
    :Widget(parent, x, y, sx, sy, selectable), _back_color(parent->back_), _text_color(parent->text_), _aline_color(parent->aline_), _pline_color(parent->pline_),  _line_color(parent->pline_)
{
    _pos=pos;
    _title=title;
    _action=action;
    _pushed=false;
    _parent->push_item(this);
    if(!_selectable) _line_color=color(245,245,245);
    else _line_color=_pline_color;
}

void Button::draw() const
{

    gout << move_to(_x +1, _y+1) << _back_color << box(_size_x , _size_y )
    << move_to(_x +1 , _y +1 ) << _line_color << box(_size_x, _size_y)
    << move_to(_pushed ? _x + 1 : _x, _pushed ? _y + 1 : _y) << _line_color << box(_size_x, _size_y)
    << move_to(_pushed ? _x + 2 : _x + 1, _pushed ? _y + 2 : _y + 1) << _back_color << box(_size_x - 2, _size_y - 2);

    if(_pos=="left") gout << move_to(_pushed ? _x+5 : _x+4,_pushed ? _y+(_size_y-2)/2+gout.cascent()/2+1 : _y+(_size_y-2)/2+gout.cascent()/2) << _text_color << text(cut_title(_title, _size_x));
    if(_pos=="middle") gout << move_to(_pushed ? _x+(_size_x-2)/2-gout.twidth(cut_title(_title, _size_x))/2+1 : _x+(_size_x-2)/2-gout.twidth(cut_title(_title, _size_x))/2,_pushed ? _y+(_size_y-2)/2+gout.cascent()/2+1 : _y+(_size_y-2)/2+gout.cascent()/2) << _text_color << text(cut_title(_title, _size_x));
    if(_pos=="right") gout << move_to(_pushed ? _x+_size_x-8-gout.twidth(cut_title(_title, _size_x))+1 : _x+_size_x-8-gout.twidth(cut_title(_title, _size_x)), _pushed ? _y+(_size_y-2)/2+gout.cascent()/2+1 : _y+(_size_y-2)/2+gout.cascent()/2) << _text_color << text(cut_title(_title, _size_x));

}

void Button::handle(genv::event ev)
{
        if(is_hover(ev.pos_x, ev.pos_y) && ev.button == btn_left)
        {
            set_pushed(true);
        }
        if(is_hover(ev.pos_x, ev.pos_y) && ev.button == -btn_left)
        {
            set_pushed(false);
            _action();
        }
}

void Button::set_action(function<void()> action)
{
    _action=action;
}

string Button::get_title() const
{
    return _title;
}

void Button::set_title_(string title)
{
    _title = title;
}

void Button::set_selectable(bool selectable)
{
    _selectable=selectable;
    if(!_selectable) _line_color=color(245,245,245);
    else _line_color=_pline_color;
}

void Button::set_pushed(bool pushed)
{
    _pushed=pushed;
}

bool Button::is_hover(int mouse_posx, int mouse_posy)
{
    bool asd= mouse_posx < _x+_size_x && mouse_posx > _x && mouse_posy < _y+_size_y && mouse_posy > _y && _selectable;
    if(asd) _line_color=_aline_color;
    else if(_selectable) _line_color=_pline_color;
    return asd;
}



void Button::get_data(ostream & datafile, int i) const
{
    datafile <<"----"<<i<<"----"<< endl << "A gomb felirata: " << _title << endl << "Erteke: " << _pushed << endl <<"----"<<i<<"----"<< endl << endl;
}
