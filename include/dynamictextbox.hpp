#ifndef DYNAMICTXTBOX_H_INCLUDED
#define DYNAMICTXTBOX_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "statictextbox.hpp"

using namespace genv;

class DynamicTextBox : public StaticTextBox
{
protected:
    const string _starter;
    color _text_color, _back_color, _aline_color, _pline_color;
    color _line_color;
public:
    DynamicTextBox(Window * parent, int x, int y, int sx, int sy, bool selectable, string pos, string title, bool boxed);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual void set_selected(bool selected);
    virtual void get_data(ostream & datafile, int i) const;
};

#endif // DYNAMICTXTBOX_H_INCLUDED
