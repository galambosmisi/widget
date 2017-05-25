#include "window.hpp"
#include "graphics.hpp"
#include <fstream>

using namespace genv;

Window::Window(int XX, int YY, color back_color, color text_color, color aline_color, color pline_color, color bg_color): _XX(XX), _YY(YY), back_(back_color), text_(text_color), aline_(aline_color), pline_(pline_color), back_ground(bg_color), _run(true), focus(-1) {}
void Window::push_item(Widget * w)
{
    widgets.push_back(w);
}

void Window::set_run(bool run)
{
    _run=run;
}

void Window::clear_screen() const
{
    gout << move_to(0,0) << back_ground << box(_XX,_YY);
}

void Window::event_loop()
{
    string datafile="data_from_"+name+".txt";
    ofstream kifele(datafile);

    event ev;
    gout.open(_XX,_YY);

    //Kirajzolás
    clear_screen();
    for (size_t i=0; i<widgets.size(); i++)
    {
        widgets[i]->draw();
    }
    gout << refresh;


    while(gin >> ev && _run)
    {
        clear_screen();
        if(ev.type == ev_mouse && ev.button == btn_left)
        {
            for (size_t i=0; i<widgets.size(); i++)
            {

                if(widgets[i]->is_hover(ev.pos_x, ev.pos_y) && widgets[i]->is_selectable())
                {
                    focus = i;
                    widgets[i]->set_selected(true);
                }
                else
                {
                    widgets[i]->set_selected(false);
                }
            }
        }
        //Kezelés
        if (focus!=-1)
        {
            widgets[focus]->handle(ev);
        }

        //Kirajzolás

        for (size_t i=0; i<widgets.size(); i++)
        {
            widgets[i]->draw();
        }
        gout << refresh;

        //Log
        if(ev.type == ev_key && ev.keycode == key_f1)
        {
            for(size_t i=0; i<widgets.size(); i++)
            {
                widgets[i]->get_data(kifele);
            }
        }
    }

    kifele.close();
}




int Window::get_XX() const
{
    return _XX;
}

int Window::get_YY() const
{
    return _YY;
}
