#ifndef CALCULATOR_HPP_INCLUDED
#define CALCULATOR_HPP_INCLUDED

#include "graphics.hpp"
#include "window.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include "checkbox.hpp"
#include "dropdownmenu.hpp"
#include "dynamictextbox.hpp"
#include "numericsetter.hpp"
#include "statictextbox.hpp"


class Calculator : public Window
{
protected:
    StaticTextBox * stx_kijelzo;

    Button * b0;
    Button * b1;
    Button * b2;
    Button * b3;
    Button * b4;
    Button * b5;
    Button * b6;
    Button * b7;
    Button * b8;
    Button * b9;
    Button * b_eq;
    Button * b_ac;
    Button * b_plus;
    Button * b_minus;

    double _a, _b, _eredmeny;
    char _operator;

public:
    Calculator(string name, int XX, int YY, color back_, color text_, color aline_, color pline_, color bg_);
    void click(int c);
};

#endif // CALCULATOR_HPP_INCLUDED
