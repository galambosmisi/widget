#include "dynamictextbox.hpp"
#include "graphics.hpp"


using namespace genv;

DynamicTextBox::DynamicTextBox(Window * parent, int x, int y, int sx, int sy, bool selectable, string pos, string title, bool boxed)
    :StaticTextBox(parent, x, y, sx, sy, selectable, pos, title, boxed), _back_color(parent->back_), _text_color(parent->text_),  _aline_color(parent->aline_), _pline_color(parent->pline_), _line_color(parent->pline_), _starter(title)
{
    _title=title;
}

void DynamicTextBox::draw() const
{
    string t;
    if(_selected) t=_title+'|';
    else t=_title;
    gout << _line_color;
    if(_boxed)
    {
        gout << move_to(_x, _y) << box(_size_x, _size_y);
        gout << move_to(_x+1, _y+1) << _back_color << box(_size_x-2, _size_y-2);
    }
    gout << _text_color;
    if(_pos=="left") gout << move_to(_x+4, _y+_size_y/2+5) << text(cut_title(t, _size_x));
    if(_pos=="middle") gout << move_to(_x+_size_x/2-gout.twidth(cut_title(t, _size_x))/2, _y+_size_y/2+5) << text(cut_title(t, _size_x));
    if(_pos=="right") gout << move_to(_x+_size_x-8-gout.twidth(cut_title(t, _size_x)), _y+_size_y/2+5) << text(cut_title(t, _size_x));
}

void DynamicTextBox::handle(genv::event ev)
{

        if(_title ==_starter && _selected) _title="";
    if((_title == "" || _title==_starter) && !_selected) _title=_starter;

    if (ev.type == ev_key && ev.keycode == key_backspace && _title.size() != 0)
    {
        _title.pop_back();
    }

    if (ev.type == ev_key && (31 < ev.keycode && ev.keycode < 256 ) && gout.twidth(_title+'|')< _size_x-8)
    {
        _title+=ev.keycode;


    }
}

void DynamicTextBox::get_data(ostream & datafile, int i) const
{
    datafile <<"----"<<i<<"----"<< endl << "A jelenlegi tartalom: " << _title << endl <<"----"<<i<<"----"<< endl;
}


