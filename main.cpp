#include "carrent.hpp"
#include "calculator.hpp"
#include "birthdaycalendar.hpp"

using namespace std;
using namespace genv;

const int XX = 650;
const int YY = 600;

color _back(245,245,245);
color _text(48,72,72);
color _aline(216,48,96);
color _pline(155,208,255);
color _bg(255,255,255);




int main()
{
    vector<string> nevek;
    nevek.push_back("Misi");
    nevek.push_back("Matyi");
    nevek.push_back("Anna");
    nevek.push_back("Katalin");
    nevek.push_back("Tamas");
    nevek.push_back("Lilla");
    nevek.push_back("Peti");
    nevek.push_back("Gergo");
    nevek.push_back("Fanni");
    nevek.push_back("Gabor");
    nevek.push_back("Kinga");


    vector<string> autok;
    autok.push_back("BMW");
    autok.push_back("Audi");
    autok.push_back("Mercedes");
    autok.push_back("Honda");
    autok.push_back("Suzuki");
    autok.push_back("Toyota");
    autok.push_back("Kia");
    autok.push_back("Ford");
    autok.push_back("Skoda");


    //CarRent voros_car("voros_auto", 710, 600, _back, _text, _aline, _pline, _bg, nevek, autok);
    //voros_car.event_loop();

    //Calculator szamologep("szamologep", 235, 290, _back, _text, _aline, _pline, _bg);
    //szamologep.event_loop();

    MyBirthdayCalendar szulinapok("szulinapok", 650, 600, _back, _text, _aline, _pline, _bg);
    szulinapok.event_loop();

    return 0;
}
