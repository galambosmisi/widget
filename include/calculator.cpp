#include "calculator.hpp"
#include <sstream>

Calculator::Calculator(string name, int XX, int YY, color back_, color text_, color aline_, color pline_, color bg_)
:Window(name, XX, YY, back_, text_, aline_, pline_, bg_), _a(0), _b(0), _eredmeny(0), _operator(0)
{
    stx_kijelzo = new StaticTextBox(this, 10, 10, 215, 50, true, "right", "0", true);
             b7 = new Button(this, 10,   65,   50,  50, true, "middle", "7",  [this](){click(7);});
             b8 = new Button(this, 65,   65,   50,  50, true, "middle", "8",  [this](){click(8);});
             b9 = new Button(this, 120,  65,   50,  50, true, "middle", "9",  [this](){click(9);});
           b_ac = new Button(this, 175,  65,   50,  50, true, "middle", "C", [this](){_operator='c'; click(-1);});
             b4 = new Button(this, 10,   120,  50,  50, true, "middle", "4",  [this](){click(4);});
             b5 = new Button(this, 65,   120,  50,  50, true, "middle", "5",  [this](){click(5);});
             b6 = new Button(this, 120,  120,  50,  50, true, "middle", "6",  [this](){click(6);});
        b_minus = new Button(this, 175,  120,  50,  50, true, "middle", "-",  [this](){_operator='-'; click(-1);});
             b1 = new Button(this, 10,   175,  50,  50, true, "middle", "1",  [this](){click(1);});
             b2 = new Button(this, 65,   175,  50,  50, true, "middle", "2",  [this](){click(2);});
             b3 = new Button(this, 120,  175,  50,  50, true, "middle", "3",  [this](){click(3);});
         b_plus = new Button(this, 175,  175,  50,  50, true, "middle", "+",  [this](){_operator='+'; click(-1);});
             b0 = new Button(this, 10,   230,  160, 50, true, "middle", "0",  [this](){click(0);});
           b_eq = new Button(this, 175,  230,  50,  50, true, "middle", "=",  [this](){_operator='='; click(-1);});

}

void Calculator::click(int c)
{
        if(c >=0)
        {
            if(_operator != '+' && _operator != '-')
            {
                _a *= 10;
                _a += c;
            }
            else
            {
                _b *= 10;
                _b += c;
            }
            if(_operator == '+') _eredmeny = _a + _b;
            if(_operator == '-') _eredmeny = _a - _b;
            if(_operator == 'c') _eredmeny = 0;
        }
        else
        {
            if(_operator == 'c')
            {
                _a = 0;
                _b = 0;
                _operator = '0';
            }

            if(_operator == '=')
            {
                _a = _eredmeny;
                _b = 0;
                _operator = '0';
            }
        }

    stringstream ss;
    ss.clear();
    ss.str("");
    if(_operator != '=')
    {
        ss << _a;
        if(_operator == '+' || _operator =='-') ss << " " << _operator;
        if(_b != 0)                             ss << " " << _b;
    }
    else ss  << _eredmeny;
    stx_kijelzo->set_title(stx_kijelzo->cut_title(ss.str(), 127));
}
