#include "numericsetter.hpp"
#include "graphics.hpp"
#include <sstream>

using namespace genv;

NumericSetter::NumericSetter(Window * parent, int x, int y, int sx, int sy, bool selectable, int min_, int max_ )
    :Widget(parent, x, y, sx, sy, selectable), _back_color(parent->back_), _text_color(parent->text_), _aline_color(parent->aline_), _pline_color(parent->pline_), _line_color(parent->pline_)
{
    _min=min_;
    _max=max_;
    _num=min_;
    box_size=_size_y/2;
    _parent->push_item(this);
}



void NumericSetter::draw() const
{
    stringstream ss;
    ss<<_num;

    //Keret
    gout << move_to(_x, _y) << _line_color << box(_size_x, _size_y);
    gout << move_to(_x+1, _y+1) << _back_color << box(_size_x-2, _size_y-2);

    gout << move_to(_x+_size_x-box_size,_y) << _line_color<< line_to(_x+_size_x-box_size,_y+_size_y-1);
    gout << move_to(_x+_size_x-box_size,_y+box_size) << line_to(_x+_size_x-1,_y+box_size);

    //Szöveg
    gout<<_text_color;
    if (gout.twidth(ss.str())<= _size_x-box_size-8)
        gout << move_to(_x+_size_x-box_size-gout.twidth(ss.str())-4, _y+_size_y/2+gout.cascent()/2) << text(ss.str());

    //Nyilak
    gout << move_to(_x+_size_x-box_size/2,_y+box_size/2-box_size/4) << line_to(_x+_size_x-box_size/2+box_size/4,_y+box_size/2+box_size/4);
    gout << move_to(_x+_size_x-box_size/2,_y+box_size/2-box_size/4) << line_to(_x+_size_x-box_size/2-box_size/4,_y+box_size/2+box_size/4);
    gout << move_to(_x+_size_x-box_size/2,_y+3*box_size/2+box_size/4) << line_to(_x+_size_x-box_size/2+box_size/4,_y+3*box_size/2-box_size/4);
    gout << move_to(_x+_size_x-box_size/2,_y+3*box_size/2+box_size/4) << line_to(_x+_size_x-box_size/2-box_size/4,_y+3*box_size/2-box_size/4);
}

void NumericSetter::handle(genv::event ev)
{
        if (ev.type == ev_key && ev.keycode == key_up && _num!=_max) _num++;
        if (ev.type == ev_key && ev.keycode == key_down && _num!=_min) _num--;
        if (ev.type == ev_key && ev.keycode == key_pgup && _num+10<_max) _num+=10;
        if (ev.type == ev_key && ev.keycode == key_pgdn && _num-10>_min) _num-=10;
        if (ev.type == ev_mouse && ev.button==btn_left && ev.pos_x<_x+_size_x-1 && ev.pos_x>_x+_size_x-box_size+1 && ev.pos_y>_y && ev.pos_y<_y+box_size && _num!=_max) _num++;
        if (ev.type == ev_mouse && ev.button==btn_left && ev.pos_x<_x+_size_x-1 && ev.pos_x>_x+_size_x-box_size+1 && ev.pos_y>_y+box_size && ev.pos_y<_y+2*box_size && _num!=_min) _num--;
}

void NumericSetter::set_selected(bool selected)
{
    _selected=selected;
    if(selected) _line_color = _aline_color;
    else _line_color = _pline_color;
}

int NumericSetter::get_num() const
{
    return _num;
}

void NumericSetter::get_data(ostream & datafile, int i) const
{
    datafile <<"----"<<i<<"----"<< endl << "Szambeallito erteke: " << _num << endl <<"----"<<i<<"----"<< endl << endl;
}
