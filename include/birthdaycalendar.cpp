#include "birthdaycalendar.hpp"
#include <sstream>

MyBirthdayCalendar::MyBirthdayCalendar(string name, int XX, int YY, color back_, color text_, color aline_, color pline_, color bg_)
    :Window(name, XX, YY, back_, text_, aline_, pline_, bg_)
{
            _filter.push_back("Minden");
            _filter.push_back("Januar");
            _filter.push_back("Februar");
            _filter.push_back("Marcius");
            _filter.push_back("Aprilis");
            _filter.push_back("Majus");
            _filter.push_back("Junius");
            _filter.push_back("Julius");
            _filter.push_back("Augusztus");
            _filter.push_back("Szeptember");
            _filter.push_back("Oktober");
            _filter.push_back("November");
            _filter.push_back("December");

            stx1 = new StaticTextBox(this, 10,  10,  200, 30, false, "left", "Nev", false);
            stx2 = new StaticTextBox(this, 240, 10,  60,  30, false, "middle", "Ho", false);
            stx3 = new StaticTextBox(this, 330, 10,  60,  30, false, "middle", "Nap", false);
            stx4 = new StaticTextBox(this, 10,  100, 320, 30, false, "left", "Szuletesnapok:", false);
            stx5 = new StaticTextBox(this, 360, 100, 90,  30, false, "middle", "Filter", false);
             dtx = new DynamicTextBox(this, 10, 40, 200, 30, true, "left", "Ide irhat..", true);
           b_add = new Button(this, 420, 40, 130, 30, true, "middle", "Hozzaad", [this]()
                              {
                                if(dtx->has_changed())
                                {
                                    stringstream ss;
                                    ss<<dtx->get_title()<<" ("<<ho->get_num()<<". "<<nap->get_num()<<".)";
                                    szulinapok->add_item(ss.str());
                                    _szulinapok.push_back(ss.str());
                                    int id = ho->get_num();
                                    if(id==1) _jan.push_back(ss.str());
                                    if(id==2) _feb.push_back(ss.str());
                                    if(id==3) _mar.push_back(ss.str());
                                    if(id==4) _apr.push_back(ss.str());
                                    if(id==5) _maj.push_back(ss.str());
                                    if(id==6) _jun.push_back(ss.str());
                                    if(id==7) _jul.push_back(ss.str());
                                    if(id==8) _aug.push_back(ss.str());
                                    if(id==9) _szep.push_back(ss.str());
                                    if(id==10) _okt.push_back(ss.str());
                                    if(id==11) _nov.push_back(ss.str());
                                    if(id==12) _dec.push_back(ss.str());
                                    dtx->reset();
                                    ho->reset();
                                    nap->reset();
                                }
                              });
        b_filter = new Button(this, 490, 130, 60, 30, true, "middle", "search", [this]()
                              {

                                    int id = filter->get_actual_itme_idx();
                                    if(id==0) szulinapok->change_items(_szulinapok);
                                    if(id==1) szulinapok->change_items(_jan);
                                    if(id==2) szulinapok->change_items(_feb);
                                    if(id==3) szulinapok->change_items(_mar);
                                    if(id==4) szulinapok->change_items(_apr);
                                    if(id==5) szulinapok->change_items(_maj);
                                    if(id==6) szulinapok->change_items(_jun);
                                    if(id==7) szulinapok->change_items(_jul);
                                    if(id==8) szulinapok->change_items(_aug);
                                    if(id==9) szulinapok->change_items(_szep);
                                    if(id==10) szulinapok->change_items(_okt);
                                    if(id==11) szulinapok->change_items(_nov);
                                    if(id==12) szulinapok->change_items(_dec);
                              });
      szulinapok = new DropDownMenu(this, 10, 130, 320, 30, true, false, 15, _szulinapok);
          filter = new DropDownMenu(this, 340, 130, 140, 30, true, false, 13, _filter);
              ho = new NumericSetter(this, 240, 40, 60, 30, true, 1, 12);
             nap = new NumericSetter(this, 330, 40, 60, 30, true, 1, 31);
}
