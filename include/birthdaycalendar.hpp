#ifndef BIRTHDAYCALENDAR_HPP_INCLUDED
#define BIRTHDAYCALENDAR_HPP_INCLUDED

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


class MyBirthdayCalendar : public Window
{
protected:
    StaticTextBox * stx1;
    StaticTextBox * stx2;
    StaticTextBox * stx3;
    StaticTextBox * stx4;
    StaticTextBox * stx5;
   DynamicTextBox * dtx;
           Button * b_add;
           Button * b_filter;
     DropDownMenu * szulinapok;
     DropDownMenu * filter;
    NumericSetter * ho;
    NumericSetter * nap;

    vector<string> _szulinapok;
    vector<string> _filter;
    vector<string> _jan;
    vector<string> _feb;
    vector<string> _mar;
    vector<string> _apr;
    vector<string> _maj;
    vector<string> _jun;
    vector<string> _jul;
    vector<string> _aug;
    vector<string> _szep;
    vector<string> _okt;
    vector<string> _nov;
    vector<string> _dec;

public:
    MyBirthdayCalendar(string name, int XX, int YY, color back_, color text_, color aline_, color pline_, color bg_);
};

#endif // BIRTHDAYCALENDAR_HPP_INCLUDED
