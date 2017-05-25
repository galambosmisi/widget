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

color _back(255,255,255);
color _text(0,0,0);
color _aline(218,165,32);
color _pline(0,0,0);
color _bg(176,196,222);


class MyWindow : public Window
{
protected:
Button * b1;
Button * b2;
DynamicTextBox * dtx1;

public:
    MyWindow(int XX, int YY, color back_, color text_, color aline_, color pline_, color bg_)
    :Window(XX,YY,back_,text_,aline_,pline_,bg_)
    {
        b1 = new Button(this, 10, 10, 100, 30, true, "middle", "Gomb", [](){});
        b2 = new Button(this, 10, 50, 100, 30, true, "middle", "Gomb", [](){});
        dtx1 = new DynamicTextBox(this, 10, 90, 120, 30, true, "middle", "Ide valami nagyon hosszú szöveg...", true);
    }
};


/*class Calculator : public Window
{
protected:
    Button *b0, *b1, *b2, *b3, *b4, *b5, *b6, *b7, *b8, *b9, *plusz, *minusz, *eq;
    StatString *screen;
    int _a, _b, _eredmeny;
    char _op;
public:
    Calculator(int XX,int YY);
    void append(int c);
    void set_screen();
};

void Calculator::set_screen()
{
    stringstream scr;
    if(_op != '=')
    {
        scr << _a;
        if(_op != '0')
            scr << " " << _op;
        if(_b != 0)
            scr << " " << _b;
    }
    else
        scr << "ans = " << _eredmeny;
    screen->set_body(scr.str());
}

void Calculator::append(int c)
{
    if(_op == '=')
    {
        _a = 0;
        _b = 0;
        _op = '0';
    }
    if(_op == '0')
    {
        _a *= 10;
        _a += c;
    }
    else
    {
        _b *= 10;
        _b += c;
    }
    if(_op == '+')
        _eredmeny = _a + _b;
    if(_op == '-')
        _eredmeny = _a - _b;
    set_screen();
}

Calculator::Calculator(int XX, int YY)
    : Window(XX,YY), _a(0), _b(0), _eredmeny(0), _op('0')
{
    screen = new StatString(150,100,200,30,"Type something");

    b7 = new Button(150,150,40,30,"7",[this](){append(7);});
    b8 = new Button(200,150,40,30,"8",[this](){append(8);});
    b9 = new Button(250,150,40,30,"9",[this](){append(9);});
    b4 = new Button(150,200,40,30,"4",[this](){append(4);});
    b5 = new Button(200,200,40,30,"5",[this](){append(5);});
    b6 = new Button(250,200,40,30,"6",[this](){append(6);});
    b1 = new Button(150,250,40,30,"1",[this](){append(1);});
    b2 = new Button(200,250,40,30,"2",[this](){append(2);});
    b3 = new Button(250,250,40,30,"3",[this](){append(3);});
    b0 = new Button(200,300,40,30,"0",[this](){append(0);});

    plusz = new Button(350,150,40,30,"+",[this](){_op = '+'; set_screen();});
    minusz = new Button(350,200,40,30,"-",[this](){_op = '-'; set_screen();});
    eq = new Button(350,250,40,30,"=",[this](){_op = '='; set_screen();});

    widgets.push_back(screen);

    widgets.push_back(b0);
    widgets.push_back(b1);
    widgets.push_back(b2);
    widgets.push_back(b3);
    widgets.push_back(b4);
    widgets.push_back(b5);
    widgets.push_back(b6);
    widgets.push_back(b7);
    widgets.push_back(b8);
    widgets.push_back(b9);

    widgets.push_back(plusz);
    widgets.push_back(minusz);
    widgets.push_back(eq);
}*/



int main()
{
    MyWindow probe(XX,YY,_back, _text, _aline, _pline, _bg);
    probe.event_loop();
    return 0;
}
