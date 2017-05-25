#include "carrent.hpp"

using namespace genv;

CarRent::CarRent(string name, int XX, int YY, color back_, color text_, color aline_, color pline_, color bg_, vector<string> nevek, vector<string> autok)
:Window(name, XX,YY,back_,text_,aline_,pline_,bg_)
    {
        stx_nevek = new StaticTextBox(this, 10, 10, 150, 30, false, "middle", "Nevek:", false);
        stx_autok = new StaticTextBox(this, 170, 10, 150, 30, false, "middle", "Autok:", false);
        stx_berlesek = new StaticTextBox(this, 440, 10, 150, 30, false, "middle", "Berlesek:", false);
        berles_nev = new DropDownMenu(this, 10, 50, 150, 30, true, 5, nevek);
        berles_auto = new DropDownMenu(this, 170, 50, 150, 30, true, 10, autok);
        berles = new Button(this, 330, 30, 100, 30, true, "middle", "Berles", [this]()
        {
            ki_berles->add_item(berles_nev->get_actual_itme() +" - "+berles_auto->get_actual_itme());
            _nevek.push_back(berles_nev->get_actual_itme());
            _autok.push_back(berles_auto->get_actual_itme());
            berles_nev->delet_actual_item();
            berles_auto->delet_actual_item();
        });
        berles = new Button(this, 330, 70, 100, 30, true, "middle", "Vissza", [this]()
        {

            if(ki_berles->get_actual_itme_idx() != -1)
            {


                if(_autok.size() > 0)
                {
                    _autok.erase(_autok.begin()+ki_berles->get_actual_itme_idx());
                    berles_auto->add_item(_autok[ki_berles->get_actual_itme_idx()]);
                }

                if(_nevek.size() > 0)
                {
                    _nevek.erase(_nevek.begin()+ki_berles->get_actual_itme_idx());
                    berles_nev->add_item(_nevek[ki_berles->get_actual_itme_idx()]);
                }
                ki_berles->delet_actual_item();
            }

        });
        ki_berles = new DropDownMenu(this, 440,50,150, 30, true, 18, _berles);
    }
