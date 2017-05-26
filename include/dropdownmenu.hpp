#ifndef DROPDOWNMENU_HPP_INCLUDED
#define DROPDOWNMENU_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>

using namespace std;

class DropDownMenu : public Widget
{
protected:
    vector <string> items;
    double box_size, slider_size, ex_size_x, ex_size_y;
    int actual, _max_item, first_item;
    bool isExtended;
    bool _closeable=false;
    bool click = false;
    color _text_color, _back_color, _aline_color, _pline_color;
    color _line_color;

public:
    DropDownMenu(Window * parent,int x, int y, int sx, int sy, bool selectable, bool closeable, int max_item, vector <string>& s);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual bool has_item();
    virtual void add_item(string s);
    virtual void set_selected(bool selected);
    virtual void delet_actual_item();
    virtual void delet_item_by_idx(int idx);
    virtual void change_items(vector<string> items_);
    virtual void set_ex_size();
    virtual string get_actual_itme() const;
    virtual int get_actual_itme_idx() const;
    virtual void get_data(ostream & datafile, int i) const;
    virtual bool is_hover(int mouse_posx, int mouse_posy);
};

#endif // DROPDOWNMENU_HPP_INCLUDED
