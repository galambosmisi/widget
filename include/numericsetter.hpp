#ifndef NUMERICSETTER_HPP_INCLUDED
#define NUMERICSETTER_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

using namespace genv;

class NumericSetter : public Widget
{
protected:
    int _min, _max, _num;
    double box_size;
    color _text_color, _back_color, _aline_color, _pline_color;
    color _line_color;
public:
    NumericSetter(Window * parent, int x, int y, int sx, int sy, bool selectabel, int min_, int max_ );
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual void set_selected(bool selected);
    virtual int get_num() const ;
    virtual void get_data(ostream & datafile, int i) const;
};

#endif // NUMERICSETTER_HPP_INCLUDED
