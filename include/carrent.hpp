#ifndef CARRENT_HPP_INCLUDED
#define CARRENT_HPP_INCLUDED

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

class CarRent : public Window
{
protected:
    StaticTextBox * stx_nevek;
    StaticTextBox * stx_autok;
    StaticTextBox * stx_berlesek;
    Button * berles;
    Button * visszahoz;
    DropDownMenu * berles_nev;
    DropDownMenu * berles_auto;
    DropDownMenu * ki_berles;

    vector<string> _autok;
    vector<string> _nevek;
    vector<string> _berles;

public:
    CarRent(string name, int XX, int YY, color back_, color text_, color aline_, color pline_, color bg_, vector<string> nevek, vector<string> autok);
};

#endif // CARRENT_HPP_INCLUDED
