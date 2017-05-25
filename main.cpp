#include "graphics.hpp"
#include "window.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include "checkbox.hpp"
#include "dropdownmenu.hpp"
#include "dynamictextbox.hpp"
#include "numericsetter.hpp"
#include "statictextbox.hpp"
#include <vector>

using namespace std;
using namespace genv;

const int XX = 1200;
const int YY = 800;

color _back(245,245,245);
color _text(48,72,72);
color _aline(216,48,96);
color _pline(155,208,255);
color _bg(255,255,255);


class MyWindow : public Window
{
protected:
Button * b1;
Button * b2;
DynamicTextBox * dtx1;
DropDownMenu * m1;

public:
    MyWindow(string name, int XX, int YY, color back_, color text_, color aline_, color pline_, color bg_)
    :Window(name, XX,YY,back_,text_,aline_,pline_,bg_)
    {
        vector<string> items;
        items.push_back("1");
        items.push_back("2");
        items.push_back("3");
        items.push_back("4");
        items.push_back("5");
        items.push_back("6");
        items.push_back("7");
        items.push_back("8");

        b1 = new Button(this, 10, 10, 100, 30, true, "middle", "ADD", [this](){m1->add_answer(dtx1->get_title());});
        b2 = new Button(this, 10, 50, 100, 30, true, "middle", "DELETE", [this](){m1->delet_actual_answer();});
        dtx1 = new DynamicTextBox(this, 10, 90, 300, 30, true, "middle", "Ide valami nagyon hosszú szöveg...", true);
        m1 = new DropDownMenu(this, 600,10,200,30,true, 4, items);
    }
};

int main()
{
    MyWindow probe("teszt",XX,YY,_back, _text, _aline, _pline, _bg);
    probe.event_loop();
    return 0;
}
