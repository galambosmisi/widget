#include "dropdownmenu.hpp"
#include "graphics.hpp"
#include <sstream>
#include <vector>
#include <iostream>


using namespace genv;


DropDownMenu::DropDownMenu(Window * parent, int x, int y, int sx, int sy, bool selectable, bool closeable, int max_item, vector <string>& s)
    : Widget(parent, x, y, sx, sy, selectable), _back_color(parent->back_), _text_color(parent->text_), _aline_color(parent->aline_), _pline_color(parent->pline_), _line_color(parent->pline_)
{
    for(unsigned int i=0; i<s.size(); i++)
    {
        items.push_back(s[i]);
    }
    _closeable=closeable;
    _max_item=max_item;
    first_item=0;
    box_size=_size_y;
    actual=0;
    click=false;
    set_ex_size();
    if(items.size()-max_item!=0) slider_size=(items.size()-1)*_size_y/(items.size()-1-(max_item-1));
    if(items.size()-max_item==0 || items.size()-max_item==1) slider_size=ex_size_y-box_size;
    if(!closeable) isExtended=true;
    else isExtended=false;
    _parent->push_item(this);
}

string DropDownMenu::get_actual_itme() const
{
    return items[actual];
}

bool DropDownMenu::has_item()
{
    return items.size() > 0;
}

void DropDownMenu::set_ex_size()
{
    ex_size_x=_size_x;
    if(_max_item*_size_y  < items.size()*_size_y) ex_size_y=_size_y*(_max_item+1);
    else ex_size_y=items.size()*_size_y;
}

void DropDownMenu::draw() const
{

    //Standard keret
    gout << move_to(_x, _y) << _line_color << box(_size_x, _size_y);
    gout << move_to(_x+1, _y+1) << _back_color << box(_size_x-2, _size_y-2);

    gout << _line_color << move_to(_x+_size_x-box_size-1, _y) << line_to(_x+_size_x-box_size-1, _y+box_size-1); //A -1 es eltolások azért vannak, mert a box belső élét színezem

    //Szöveg
    gout<<_text_color;
    string s = "Empty.. :(";
    if(items.size() > 0) s = items[actual];
    gout << move_to(_x+4, _y+_size_y/2+5) << text(cut_title(s, _size_x-box_size-8));

    //Nyil
    if(!isExtended && items.size() > 1 && _closeable)
    {
        gout << move_to(_x+_size_x-box_size/2,_y+box_size/2+box_size/4) << _text_color << line_to(_x+_size_x-box_size/2+box_size/4,_y+box_size/2-box_size/4);
        gout << move_to(_x+_size_x-box_size/2,_y+box_size/2+box_size/4) << _text_color << line_to(_x+_size_x-box_size/2-box_size/4,_y+box_size/2-box_size/4);
    }
    else if(items.size() > 1 && _closeable)
    {
        gout << move_to(_x+_size_x-box_size/2,_y+box_size/2-box_size/4) << _text_color << line_to(_x+_size_x-box_size/2+box_size/4,_y+box_size/2+box_size/4);
        gout << move_to(_x+_size_x-box_size/2,_y+box_size/2-box_size/4) << _text_color << line_to(_x+_size_x-box_size/2-box_size/4,_y+box_size/2+box_size/4);
    }
    else
    {
        gout << move_to(_x+_size_x-box_size+4,_y+box_size/2) << _text_color << line(box_size-8,0);
    }

    int   XX=_size_x-13;
    int   YY=(items.size()-1)*_size_y;
    canvas C;
    C.open(XX+13, YY); //Slider miatt +13
    C.transparent(false);

    //Active keret
    if(isExtended && items.size() > 1)
    {

        //Keret
        C << move_to(0,0) << _back_color << box(XX,YY);
        C << _line_color << move_to(0,0) << line_to(0,YY) << move_to(XX-1,0) << line_to(XX-1,YY);

        //Szöveg
        stringstream ss;
        int j=0;
        for(unsigned int i=0; i<items.size()-1 && items.size()-1>0; i++)
        {
            ss.clear();
            ss.str("");
            if(i==actual) j++;
            string s = items[j];
            C << color(0,0,0) << move_to(4,_size_y+i*_size_y-_size_y/2+gout.cascent()/2) << text(cut_title(s, _size_x-14));
            //Keret
            C << _line_color << move_to(0,_size_y+i*_size_y-1) << line_to(XX, _size_y+i*_size_y);
            j++;
        }

        //Slider
        if(slider_size>=0)
        {

            C << move_to(XX,0) << _line_color << box(13,YY);
            C << move_to(XX,0) << _back_color << box(12,YY-1);


            C << _line_color << move_to(XX, _max_item*_size_y-1+first_item*_size_y) << line(13,0);
            C << move_to(XX+1,1+first_item*slider_size) <<  box(10,slider_size-3);
        }

        if(YY <= _max_item*_size_y && YY > 0) gout << stamp(C,_x,_y+_size_y);
        if(YY > _max_item*_size_y) gout << stamp(C, 0, 0+first_item*_size_y, XX+13, _max_item*_size_y, _x,_y+_size_y);
    }

}

void DropDownMenu::set_selected(bool selected)
{
    _selected=selected;
    if(_selected) _line_color = _aline_color;
    else _line_color = _pline_color;
}

bool DropDownMenu::is_hover(int mouse_posx, int mouse_posy)
{
    bool asd=false;
    if(!isExtended)
    {
        asd=mouse_posx < _x+_size_x && mouse_posx > _x && mouse_posy < _y+_size_y && mouse_posy > _y;
    }
    else
    {
        asd=mouse_posx < _x+ex_size_x && mouse_posx > _x && mouse_posy < _y+ex_size_y && mouse_posy > _y;
    }
    return asd;
}

void DropDownMenu::handle(event ev)
{


        set_ex_size();
        if((!_selected || items.size()==0) && _closeable) isExtended=false;
        if(ev.button == btn_left) click=true;
        if(ev.button == -btn_left) click=false;
        if(ev.type == ev_mouse && ev.button==btn_left)
        {
            //Extend
            if(!isExtended && ev.pos_x > _x &&  ev.pos_x <_x+_size_x-box_size && ev.pos_y > _y  && ev.pos_y < _y+_size_y && items.size()>1 && _closeable)
            {
                isExtended=true;
                first_item=0;
            }
            if(ev.pos_x > _x+_size_x-box_size &&  ev.pos_x <_x+_size_x && ev.pos_y > _y  && ev.pos_y < _y+_size_y && items.size()>1 && _closeable)
            {
                isExtended=!isExtended;
                first_item=0;
            }

            //Select
            if(isExtended && ev.pos_x > _x && ev.pos_x < _x+_size_x-14)
            {
                int limit;
                if(_max_item<items.size()) limit=_max_item+1;
                else limit=items.size()-1;
                for(unsigned int i=0; i<limit && limit>0; i++)
                {
                    if(ev.pos_y >_y+_size_y+i*_size_y && ev.pos_y < _y+_size_y+(i+1)*_size_y)
                    {
                        if(actual<=i+first_item) i++;
                        actual=i+first_item;
                        if(_closeable) isExtended=!isExtended;
                    }
                }
            }
            //Scroll
            if(isExtended && ev.pos_x > _x+_size_x-13 && ev.pos_x < _x+_size_x && items.size()>_max_item)
            {
                double _size=(_max_item*_size_y)/(items.size()-1-(_max_item-1));
                for(unsigned int i=0; i<items.size()-1-(_max_item-1); i++)
                {
                    if(ev.pos_y >= _y+_size_y+i*_size && ev.pos_y <= _y+_size_y+(i+1)*_size) first_item=i;
                    if(i > items.size()-_max_item-1) first_item=items.size()-_max_item-1;
                }
            }
        }
        //scroll
        if(click && ev.button!=btn_wheeldown && ev.button!=btn_wheelup && items.size()>_max_item)
        {
            int _size=(_max_item*_size_y)/(items.size()-1-(_max_item-1));
            for(unsigned int i=0; i<items.size()-1-(_max_item-1); i++)
            {
                if(ev.pos_y > _y+_size_y+i*_size && ev.pos_y < _y+_size_y+(i+1)*_size) first_item=i;
            }
        }
        if (ev.type == ev_mouse && ev.pos_x > _x && ev.pos_x < _x+_size_x && ev.pos_y <_y+_size_y+_max_item*_size_y && ev.pos_y > _y)
        {
            if(ev.button == btn_wheelup && first_item!=items.size()-_max_item-1) first_item+=1;
            if(ev.button == btn_wheeldown && first_item!=0) first_item-=1;
        }
        if(isExtended)
        {
            if(ev.type==ev_key && ev.keycode==key_up && first_item!=0) first_item-=1;
            if(ev.type==ev_key && ev.keycode==key_down && first_item!=items.size()-_max_item-1) first_item+=1;
        }

}

void DropDownMenu::change_items(vector<string> items_)
{
    items.clear();
    items=items_;
}

void DropDownMenu::add_item(string s)
{
    items.push_back(s);
    set_ex_size();
    if( ((int)items.size()-_max_item) > 0) slider_size=(items.size()-1)*_size_y/(items.size()-(_max_item));
    else slider_size=ex_size_y-box_size;
    if(actual >= items.size()-1) actual=0;
}

void DropDownMenu::delet_actual_item()
{
    if(items.size() > 0) items.erase(items.begin()+actual);
    if(items.size() <= 1) isExtended=false;
    set_ex_size();
    if( ((int)items.size()-_max_item) > 0) slider_size=(items.size()-1)*_size_y/(items.size()-(_max_item));
    else slider_size=ex_size_y-box_size;
    if(actual >= items.size()-1) actual=0;
}

void DropDownMenu::delet_item_by_idx(int idx)
{
    if(items.size() > 0) items.erase(items.begin()+idx);
    if(items.size() <= 1) isExtended=false;
    set_ex_size();
    if( ((int)items.size()-_max_item) > 0) slider_size=(items.size()-1)*_size_y/(items.size()-(_max_item));
    else slider_size=ex_size_y-box_size;
    if(actual >= items.size()-1) actual=0;
}

int DropDownMenu::get_actual_itme_idx() const
{
    int asd=-1;
    if(actual >= 0) asd=actual;
    return asd;
}

void DropDownMenu::get_data(ostream & datafile, int i) const
{
    datafile <<"----"<<i<<"----"<< endl << "A lista tartalma: "<< endl;
    for(size_t i=0; i<items.size(); i++)
    {
        if(i!=actual) datafile <<"  "<< i+1 <<". " << items[i] <<endl;
        else  datafile <<"  "<< i+1 <<". " << items[i] << " (actual)" <<endl;
    }
    datafile <<"----"<<i<<"----"<< endl << endl;
}
