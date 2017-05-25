#include "statictextbox.hpp"
#include "graphics.hpp"
#include <sstream>

using namespace genv;

StaticTextBox::StaticTextBox(Window * parent, int x, int y, int sx, int sy, bool selectable, string pos, string title, bool boxed)
    : Widget(parent, x, y, sx, sy, selectable), _text_color(parent->text_), _back_color(parent->back_), _aline_color(parent->aline_), _pline_color(parent->pline_), _line_color(parent->pline_)
{
    _pos=pos;
    _title=title;
    _boxed=boxed;
    _parent->push_item(this);
}



void StaticTextBox::draw() const
{
    if(_boxed)
    {
        gout << move_to(_x +1, _y+1) << _back_color << box(_size_x , _size_y )
    << move_to(_x +1 , _y +1 ) << _line_color << box(_size_x, _size_y)
    << move_to(_x, _y) << _line_color << box(_size_x, _size_y)
    << move_to(_x + 1,_y + 1) << _back_color << box(_size_x - 2, _size_y - 2);
    }
    gout << _text_color;
    if(_pos=="left") gout << move_to(_x+4, _y+_size_y/2+5) << text(cut_title(_title, _size_x));
    if(_pos=="middle") gout << move_to(_x+_size_x/2-gout.twidth(cut_title(_title, _size_x))/2, _y+_size_y/2+5) << text(cut_title(_title, _size_x));
    if(_pos=="right") gout << move_to(_x+_size_x-4-gout.twidth(cut_title(_title, _size_x)), _y+_size_y/2+5) << text(cut_title(_title, _size_x));
}

void StaticTextBox::set_title(string title)
{
    if(_selectable)
    {
        _title=title;
    }
}

string StaticTextBox::get_title() const
{
    return _title;
}

void StaticTextBox::get_data(ostream & datafile, int i) const
{
    datafile <<"----"<<i<<"----"<< endl << "A statikus text tartalma: " << _title << endl <<"----"<<i<<"----"<< endl << endl;
}


void StaticTextBox::handle(event ev) {}

